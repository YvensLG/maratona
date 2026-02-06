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
const int MAXN = 400005;

int n, k;
string s;
int q;

// next_pos[p][c] = menor índice j >= p tal que s[j] = c, ou n se não existir
vector<vector<int>> next_pos;

// dp[p] = tamanho do menor string que NÃO é subsequência de s[p..n-1]
vector<int> dp;

void solve(){
    cin >> n >> k;
    cin >> s;
    cin >> q;

    for(char &c : s) c = c - 'a';

    next_pos.resize(n+1, vector<int>(k, n));
    dp.resize(n+1, 0);

    for(int c = 0; c < k; c++){
        next_pos[n][c] = n;
    }
    for(int i = n - 1; i >= 0; i--){
        for(int c = 0; c < k; c++){
            next_pos[i][c] = next_pos[i + 1][c];
        }
        next_pos[i][s[i]] = i;
    }

    dp[n] = 1;
    for(int p = n - 1; p >= 0; p--){
        bool falta = false;
        for(int c = 0; c < k; c++){
            if(next_pos[p][c] == n){
                falta = true;
                break;
            }
        }
        if(falta){
            dp[p] = 1;
        }
        else {
            int best = INF;
            for(int c = 0; c < k; c++){
                best = min(best, 1 + dp[next_pos[p][c] + 1]);
            }
            dp[p] = best;
        }
    }

    while(q--){
        string t;
        cin >> t;

        for(char &c : t) c = c - 'a';

        int pos = 0;
        bool flag = false;
        for(char c : t){
            if(pos > n || next_pos[pos][c] == n){
                cout << 0 << "\n";
                flag = true;
                break;
            }
            pos = next_pos[pos][c] + 1;
        }
        if(flag) continue;

        cout << dp[pos] << "\n";
    }
}

signed main() { _
    solve();
    return 0;
}
