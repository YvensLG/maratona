#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

int n;
vector<int> v;

pii find(int x){
    auto lower = lower_bound(v.begin(), v.end(), x);
    int i = lower - v.begin(); 
    int j = x - *prev(lower) + i - 1;
    return {i, j};
}

void solve(){
	cin >> n;
    vector<int> a(n + 1);
    vector<int> P(n + 1);
    vector<int> Z(n + 1);
    vector<int> W(n + 1);
    vector<int> E(n + 1);

    v.pb(0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        P[i] = P[i - 1] + a[i];
        Z[i] = Z[i - 1] + P[i];
        W[i] = W[i - 1] + Z[i];
        E[i] = E[i - 1] + P[i] * (n - i);
        v.pb(n * i - (i - 1) * i / 2);
    }

    int q; cin >> q;
    // for(int i = 1; i <= n * (n + 1) / 2; i++) {
    //     pii k = find(i);
    //     cout << k.first << ' ' << k.second << '\n';
    // }

    while(q--){
        int l, r; cin >> l >> r;
        pii x = find(l);
        int a = x.F, b = x.S;
        x = find(r);
        int c = x.F, d = x.S;

        if(a == c){
            cout << Z[d] - Z[b - 1] - P[a - 1] * (d - b + 1) << '\n';
            continue;
        }

        int tot = Z[n] - Z[b - 1] - (n - b + 1) * P[a - 1];
        tot += Z[d] - Z[c - 1] - (d - c + 1) * P[c - 1];

        tot += (c - a - 1) * Z[n] - ( W[c - 2] - W[a - 1] ) - (E[c - 2] - E[a - 1]);

        cout << tot << '\n';
    }

}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}