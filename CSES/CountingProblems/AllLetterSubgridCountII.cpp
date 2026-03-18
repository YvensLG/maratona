#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
 
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 505;
const int MAXLG = 10;
const int MAXK = 26;

int jmp[MAXLG][MAXLG][MAXN][MAXN];

struct sparse {
    sparse(int n) {
        for (int pw = 1, kc = 1; pw * 2 <= n; pw *= 2, ++kc) {
            rep(i, 0, n)
                rep(j, 0, n - pw * 2 + 1)
                    jmp[0][kc][i][j] = (jmp[0][kc - 1][i][j] | jmp[0][kc - 1][i][j + pw]);
        }

        for (int pw = 1, kr = 1; pw * 2 <= n; pw *= 2, ++kr) {
            rep(kc, 0, MAXLG) {
                rep(i, 0, n - pw * 2 + 1)
                    rep(j, 0, n)
                        jmp[kr][kc][i][j] = (jmp[kr - 1][kc][i][j] | jmp[kr - 1][kc][i + pw][j]);
            }
        }
    }

    int query(int r1, int c1, int r2, int c2) {
        int lenR = r2 - r1 + 1;
        int lenC = c2 - c1 + 1;
        
        int depR = 31 - __builtin_clz(lenR);
        int depC = 31 - __builtin_clz(lenC);

        return (jmp[depR][depC][r1][c1] | 
                jmp[depR][depC][r1][c2 - (1 << depC) + 1] | 
                jmp[depR][depC][r2 - (1 << depR) + 1][c1] | 
                jmp[depR][depC][r2 - (1 << depR) + 1][c2 - (1 << depC) + 1]);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    int bst = (1 << k) - 1;

    if(k == 1) {
        cout << ((ll)n * (n + 1LL) / 2) * ((ll)n * (n + 1LL) / 2) << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            jmp[0][0][i][j] = (1 << (s[j] - 'A'));
        }
    }
     
    sparse tab(n);

    ll tot = 0;

    for(int i = 0; i < n; i++) {
        ll aux = 0;
        for(int j = 0; j < n; j++) {
            int r = n - 1, c = j;
            
            for(; r >= i; r--) {
                for(; c < n; c++)
                    if(tab.query(i, j, r, c) == bst) break;
                if(c == n) break;
                aux += n - c;
            }
        }
        tot += aux;
    }

    cout << tot << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}