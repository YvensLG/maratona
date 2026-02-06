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
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

vector<vector<int>> build(int n) {
    if (n == 1) {
        return {{0}};
    }
    
    auto prev = build(n - 1);
    int m = n - 1;
    int total = m * m;                
    vector<vector<int>> mat(n, vector<int>(n, -1));

    if (n % 2 == 0) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = prev[i][j];
                
        for (int i = 0; i < m; i++)
            mat[i][m] = total + i;
            
        for (int j = 0; j <= m; j++)
            mat[m][j] = total + m + j;
    } else {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                mat[i + 1][j + 1] = prev[i][j];
                
        for (int i = 1; i <= m; i++)
            mat[i][0] = total + (i - 1);
            
        for (int j = 0; j <= m; j++)
            mat[0][m - j] = total + m + j;
    }
    return mat;
}

void solve() {
    int n;
    cin >> n;
    auto ans = build(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() { _
    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}
