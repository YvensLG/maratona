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
    int n; cin >> n;
    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        int d; cin >> d;
        if(d != 0) pq.push({d, i + 1});
    }
    
    vector<pii> ans;

    while(pq.size() > 0) {
        vector<pii> aux;
        auto [at, pos] = pq.top(); pq.pop();

        while(at > 0) {
            if(pq.size() == 0) {
                cout << "IMPOSSIBLE\n";
                return;
            }

            auto [nxt, nxt_pos] = pq.top(); pq.pop();
            aux.push_back({nxt - 1, nxt_pos});
            ans.push_back({pos, nxt_pos});
            at--;
        }

        for(auto [x, y] : aux) if(x > 0) pq.push({x, y});
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}
