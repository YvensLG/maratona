#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long

const int MAX = 1005;
const int INF = 1e18;
// A_cheio = (0, 1); B_vazio = (1, 0), etc
vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(MAX, INF)));


void solve() {
    int a, b, x; cin >> a >> b >> x;
    dp[0][0][0] = 0; dp[0][0][b] = b;
    dp[1][0][0] = 0; dp[1][0][a] = a;
    dp[0][1][0] = a; dp[0][1][b] = a + b;
    dp[1][1][0] = b; dp[1][1][a] = a + b;

    
    for(int j = 0; j < 4 * MAX; j++)
    for(int i = 1; i < MAX; i++) {
        // FILL A
        dp[0][1][i] = min(dp[0][1][i], dp[0][0][i] + a);
        // FILL B
        dp[1][1][i] = min(dp[1][1][i], dp[1][0][i] + b);

        // EMPTY A
        dp[0][0][i] = min(dp[0][0][i], dp[0][1][i] + a);
        // EMPTY B
        dp[1][0][i] = min(dp[1][0][i], dp[1][1][i] + b);
    
        // MOVE A B
        if(i <= b) dp[0][0][i] = min(dp[1][0][i] + i, dp[0][0][i]);
        if(i >= a && i <= b) dp[0][0][i] = min(dp[0][1][i - a] + a, dp[0][0][i]); 

        if(b + i <= a) dp[1][1][i] = min(dp[1][0][b + i] + b, dp[1][1][i]);
        if(a - i >= 0 && b >= a - i) dp[1][1][i] = min(dp[1][1][i], dp[0][1][b - (a - i)] + (a - i));
    
        // MOVE B A
        if(i <= a) dp[1][0][i] = min(dp[0][0][i] + i, dp[1][0][i]);
        if(i >= b && i <= a) dp[1][0][i] = min(dp[1][1][i - b] + b, dp[1][0][i]); 

        if(a + i <= b) dp[0][1][i] = min(dp[0][0][a + i] + a, dp[0][1][i]);
        if(b - i >= 0 && a >= b - i) dp[0][1][i] = min(dp[0][1][i], dp[1][1][a - (b - i)] + (b - i));
    }

    vector<string> ans;
    int min_cost = min(dp[1][0][x], dp[1][1][x]);

    if(min_cost >= INF) {
        cout << "-1\n";
        return;
    }

    bool A = 1, c = 1;
    if(dp[1][0][x] < dp[1][1][x]) c = 0;

    while(true) {

        if((A == 0 || A == 1) && c == 0 && x == 0) break;
        if(A == 0 && c == 0 && x == b) {
            ans.push_back("FILL B");
            break; 
        }
        if(A == 1 && c == 0 && x == a) {
            ans.push_back("FILL A");
            break; 
        }
        if(A == 0 && c == 1 && x == 0) {
            ans.push_back("FILL A");
            break;
        }
        if(A == 1 && c == 1 && x == 0) {
            ans.push_back("FILL B");
            break;
        }
        if(A == 0 && c == 1 && x == b) {
            ans.push_back("FILL A");
            ans.push_back("FILL B");
            break;
        }
        if(A == 1 && c == 1 && x == a) {
            ans.push_back("FILL A");
            ans.push_back("FILL B");
            break;
        }

        if(A == 0 && c == 1) {
            // FILL A
            if(dp[0][1][x] == dp[0][0][x] + a) {
                ans.push_back("FILL A"); 
                c = 0;
            }
            // MOVE B A
            else if(b >= x && a >= b - x && dp[0][1][x] == dp[1][1][a - (b - x)] + (b - x)) {
                ans.push_back("MOVE B A");
                A = 1;
                x = a - (b - x);
            }
            else if(a + x <= b && dp[0][1][x] == dp[0][0][a + x] + a) {
                ans.push_back("MOVE B A");
                c = 0;
                x = a + x;
            }
        }
        else if(A == 1 && c == 1) {
            // FILL B
            if(dp[1][1][x] == dp[1][0][x] + b) {
                ans.push_back("FILL B"); 
                c = 0;
            }
            // MOVE A B
            else if(a >= x && b >= a - x && dp[1][1][x] == dp[0][1][b - (a - x)] + (a - x)) {
                ans.push_back("MOVE A B");
                A = 0;
                x = b - (a - x);
            }
            else if(b + x <= a && dp[1][1][x] == dp[1][0][b + x] + b) {
                ans.push_back("MOVE A B");
                c = 0;
                x = b + x;
            }
        }
        else if(A == 0 && c == 0) {
            // EMPTY A
            if(dp[0][0][x] == dp[0][1][x] + a) {
                ans.push_back("EMPTY A"); 
                c = 1;
            }
            else if(x <= b && dp[0][0][x] == dp[1][0][x] + x) {
                ans.push_back("MOVE A B");
                A = 1;
            }
            else if(x >= a && x <= b && dp[0][0][x] == dp[0][1][x - a] + a){ 
                ans.push_back("MOVE A B");
                c = 1;
                x = x - a;
            }
        }
        else if(A == 1 && c == 0) {
            // EMPTY B
            if(dp[1][0][x] == dp[1][1][x] + b) {
                ans.push_back("EMPTY B"); 
                c = 1;
            }
            else if(x <= a && dp[1][0][x] == dp[0][0][x] + x) {
                ans.push_back("MOVE B A");
                A = 0;
            }
            else if(x >= b && x <= a && dp[1][0][x] == dp[1][1][x - b] + b){ 
                ans.push_back("MOVE B A");
                c = 1;
                x = x - b;
            }
        }
    }

    cout << ans.size() << ' ';
    cout << min_cost << '\n';

    reverse(ans.begin(), ans.end());

    for(auto x : ans) cout << x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}