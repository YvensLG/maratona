#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long int  ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> graph;
 
void solve(){
    ll n, m; cin >> n >> m;
    vi ans; 
    deque<int> list;

    for(int i = 1; i <= n; i++) list.push_back(i);
    
    for(int i = n; i >= 1; i--) {
        int add = 0;
        if(m >= i - 1) {
            add = list.back(); list.pop_back();
            m -= i - 1;
        }
        else {
            add = list.front(); list.pop_front();
        }
        ans.push_back(add);
    }

    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}
