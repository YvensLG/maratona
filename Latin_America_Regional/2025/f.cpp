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

vector<pii> fact(int x) {
    vector<pii> ans;
    for(int i = 2; i * i <= x; i++) {
        if(x % i) continue; 
        int tot = 0;
        while(x % i == 0) {
            tot ++;
            x /= i;
        }
        ans.push_back({i, tot});
    }
    if(x > 1) ans.push_back({x, 1});
    return ans;
}

void solve(){
    string x; cin >> x;
    int n = x.size();
    if(n <= 11) {
        int y = stoll(x);
        vector<pii> ans = fact(y);
        cout << ans.size() << '\n';
        for(auto [p, e] : ans) {
            cout << p << ' ' << e << '\n';
        }
        return;
    }

    string s;
    for(int i = 0; i <= 11; i++) {
        s += x[i];
    }
    int y = stoll(s);
    int e2 = n - 12, e5 = n - 12;
    vector<pii> ans = fact(y);
    bool flag2 = false, flag5 = false;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i].first == 2) {
            ans[i].second += e2;
            flag2 = true;
        }
        if(ans[i].first == 5) {
            ans[i].second += e5;
            flag5 = true;
        }
    }

    if(!flag2) ans.push_back({2, e2});
    if(!flag5) ans.push_back({5, e5});

    cout << ans.size() << '\n';
    for(auto [p, e] : ans) {
        cout << p << ' ' << e << '\n';
    }
}

signed main() { _
    solve();
    return 0;
}