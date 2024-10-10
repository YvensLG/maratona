#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

void solve() {
    int n, q; cin >> n >> q;
    // vetor original
    vector<int> a(n);
    // pref[i] = quantidade de a's <= i
    vector<int> pref(n+1);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        pref[i] += pref[i-1];
    }

    // resposta para cada x
    vector<int> ans(n+1);

    for(int x = 1; x <= n; x++){
        int l = -1, r = x - 1; 
        
        while(r - l > 1){
            int m = (r + l) / 2;
            
            // conta quantos a[i] % x <= m
            int qtd = 0;
            for(int k = 0; k <= n / x; k++){
                qtd += pref[min(k * x + m, n)] - pref[max(0, k * x - 1)];
            }

            if(qtd <= n / 2) l = m;
            else r = m;
        }

        ans[x] = r;
    }

    for(int i = 0; i < q; i++){
        int x; cin >> x;
        cout << ans[x] << ' ';
    }
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}