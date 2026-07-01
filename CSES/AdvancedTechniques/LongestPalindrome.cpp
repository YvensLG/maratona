#include <bits/stdc++.h>
 
#define int long long
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

array<vi, 2> manacher(const string& s) {
    int n = sz(s);
    array<vi,2> p = {vi(n+1), vi(n)};
    rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
        int t = r-i+!z;
        if (i<r) p[z][i] = min(t, p[z][l+t]);
        int L = i-p[z][i], R = i+p[z][i]-!z;
        while (L>=1 && R+1<n && s[L-1] == s[R+1])
            p[z][i]++, L--, R++;
        if (R>r) l=L, r=R;
    }
    return p;
}

void solve(){
    string s; cin >> s;
    auto ans = manacher(s);

    int q[2] = {-1, -1}, pos[2] = {-1, -1};
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < ans[j].size(); i++) {
            if(q[j] < ans[j][i]) {
                q[j] = ans[j][i];
                pos[j] = i;
            }
        }
    }

    int bst = 0;
    if(q[0] * 2 < q[1] * 2 + 1) bst = 1;

    if(pos[bst] == 0) {
        cout << s[0] << '\n';
        return;
    }

    for(int i = pos[bst] - q[bst]; i < pos[bst] + q[bst] + bst; i++) {
        cout << s[i];
    }
    cout << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}