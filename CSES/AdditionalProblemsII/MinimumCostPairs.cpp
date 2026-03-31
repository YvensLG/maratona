#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long
 
using namespace std;

const int INF = 10000000000000000;
 
void solve(){
    int n; cin >> n;
    vector<int> x(n);

    // diferenca, L, R
    set<tuple<int, int, int>> d;
    // elementos com L = i, R = i
    vector<tuple<int, int, int>> L(n - 1), R(n - 1);
    
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(all(x));

    for(int i = 0; i < n - 1; i++) {
        d.insert({x[i + 1] - x[i], i, i});
        L[i] = {x[i + 1] - x[i], i, i};
        R[i] = {x[i + 1] - x[i], i, i};
    }

    int tot = 0;
    
    for(int k = 1; k <= n / 2; k++) {
        auto top = *d.begin(); d.erase(d.begin());
        tot += get<0>(top);
        
        tuple<int, int, int> a, b;
        // elemento tq R = top.L - 1
        if(get<1>(top) == 0) a = {INF, 0, 2 * n}; // INF pq trocar as pontas so piora
        else a = R[get<1>(top) - 1];
        
        // elemento tq L = top.R + 1
        if(get<2>(top) == n - 2) b = {INF, 2 * n, n - 2};
        else b = L[get<2>(top) + 1];
        
        d.insert({get<0>(a) + get<0>(b) - get<0>(top), get<1>(a), get<2>(b)});
        L[get<1>(a)] = {get<0>(a) + get<0>(b) - get<0>(top), get<1>(a), get<2>(b)};
        R[get<2>(b)] = {get<0>(a) + get<0>(b) - get<0>(top), get<1>(a), get<2>(b)};
        d.erase(a); d.erase(b);

        cout << tot << ' ';
    }

    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}