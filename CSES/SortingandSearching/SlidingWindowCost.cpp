#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

void fix(multiset<int>* m, multiset<int>* M, ll* sm, ll* sM){
    if((*m).size() < (*M).size()){
        int x = *(*M).begin();
        (*m).insert(x);
        (*M).erase((*M).begin());
        *sm += x;
        *sM -= x;
    }
    else if((*m).size() >= (*M).size() + 2){
        int x = *(*m).rbegin();
        (*M).insert(x);
        (*m).erase((*m).find(x));
        *sM += x;
        *sm -= x;
    }
}
 
// Sum of Two Values nos pares (i, j) do vetor original
void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];

    multiset<int> m, M;
    ll sm = 0, sM = 0;

    vector<int> aux(k);
    for(int i = 0; i < k; i++) aux[i] = v[i];
    sort(all(aux));

    for(int i = 0; i < (k + 1) / 2; i++) {
        m.insert(aux[i]);
        sm += aux[i];
    }
    for(int i = (k + 1) / 2; i < k; i++) {
        M.insert(aux[i]);
        sM += aux[i];
    }

    for(int i = 0; i < n - k + 1; i++){
        int rem = v[i];
        int add = v[i + k];
        int a = *m.rbegin();
        if(k % 2 == 1)
            cout << sM  - sm + a << ' ';
        else
            cout << sM  - sm     << ' ';
        if(rem <= a) {
            m.erase(m.find(rem));
            sm -= rem;
        }
        else {
            M.erase(M.find(rem));
            sM -= rem;
        }
        fix(&m, &M, &sm, &sM);

        if(M.empty()) {
            m.insert(add);
            sm += add;
        }
        else {
            a = *M.begin();
            if(add >= a) {
                M.insert(add);
                sM += add;
            }
            else {
                m.insert(add);
                sm += add;
            }
        }
        fix(&m, &M, &sm, &sM);
        
    }
    cout << '\n';

}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}