#include <bits/stdc++.h>
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 1e3 + 5;
 
bool M[MAX][MAX];
int v[MAX];
 
vector<int> next_smaller(int n) {
    vector<int> ans(n + 1, -1), st;
    
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && v[i] < v[st.back()]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
 
vector<int> prev_smaller(int n) {
    vector<int> ans(n + 1, -1), st;
    
    for (int i = n; i >= 0; i--) {
        while (!st.empty() && v[i] < v[st.back()]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}
 
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n + 1; i++) {
        M[i][0] = 1;
        M[i][m + 1] = 1;
    }
    for(int j = 0; j <= m + 1; j++) {
        M[0][j] = 1;
        M[n + 1][j] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; cin >> c;
            if(c == '*') M[i][j] = 1;
        }
    }
 
    int ans = 0;
 
    for(int i = 1; i <= n; i++) {
        v[0] = -1; v[m + 1] = -1;
        for(int j = 1; j <= m; j++) {
            if(M[i][j]) v[j] = 0;
            else v[j]++;
        }
 
        auto nxt = next_smaller(m + 1);
        auto prev = prev_smaller(m + 1);
 
        for(int j = 1; j <= m; j++) {
            int h = v[j], w = nxt[j] - prev[j] - 1;
            ans = max(ans, h * w);
        }
    }
 
    cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}