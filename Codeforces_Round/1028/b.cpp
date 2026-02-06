#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define INF 1000000000
#define LINF 1000000000000000000LL
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MOD = 998244353;
const int MAX = 100005;
vector<int> pow2(MAX);

bool better(int x1, int y1, int x2, int y2){
    if(x1 < y1) swap(x1,y1);
    if(x2 < y2) swap(x2,y2);
    if(x1 != x2) return x1 > x2;
    return y1 > y2;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n), q(n);
    for(int &x: p) cin >> x;
    for(int &x: q) cin >> x;

    vector<int> ans(n);

    int pmax = -1, pmaxi = -1;
    int qmax = -1, qmaxi = -1;

    for(int i = 0; i < n; i++){
        if(p[i] > pmax){ pmax = p[i]; pmaxi = i; }
        if(q[i] > qmax){ qmax = q[i]; qmaxi = i; }

        int a1 = p[pmaxi];
        int b1 = q[i - pmaxi];

        int a2 = p[i - qmaxi];
        int b2 = q[qmaxi];

        int A, B;
        if(better(a1,b1,a2,b2)){ A = a1; B = b1; }
        else{ A = a2; B = b2; }

        ans[i] = (pow2[A] + pow2[B]) % MOD;
    }

    for(int i=0;i<n;++i){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main(){ _
    pow2[0] = 1;
    for(int k = 1; k < MAX; k++)
        pow2[k] = (pow2[k-1] * 2) % MOD;

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
