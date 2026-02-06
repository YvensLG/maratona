#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
void solve(){
    int n, m; cin >> n >> m;
    char M[n + 2][m + 2];
    
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++)
            M[i][j] = 'A';

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> M[i][j];
    
    for(int sum = 2; sum <= m + n; sum++)
    {
        for(int i = max(1, sum - m); i <= min(n, sum - 1); i++)
        {
            int j = sum - i;
            for(int k = 0; k < 4; k++)
            {
                if(M[i][j] - 'A' == k || M[i - 1][j] - 'A' == k || M[i][j - 1] - 'A' == k) continue;
                M[i][j] = 'A' + k;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << M[i][j];
        }
        cout << '\n';
    }
}   
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}