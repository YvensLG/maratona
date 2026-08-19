const int MAXN = 505;
const int MAXLG = 9;

int jmp[MAXLG][MAXLG][MAXN][MAXN];
int lg[MAXN];
int pw[MAXLG];

inline int query(int r1, int c1, int r2, int c2) __attribute__((always_inline));
inline int query(int r1, int c1, int r2, int c2) {
    int depR = lg[r2 - r1 + 1];
    int depC = lg[c2 - c1 + 1];
    int pwR = pw[depR];
    int pwC = pw[depC];

    return jmp[depR][depC][r1][c1] |
           jmp[depR][depC][r1][c2 - pwC + 1] |
           jmp[depR][depC][r2 - pwR + 1][c1] |
           jmp[depR][depC][r2 - pwR + 1][c2 - pwC + 1];
}

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

    // build
    for (int kc = 1; kc < MAXLG; ++kc) {
        int lenC = pw[kc-1];
        if(lenC > n) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n - pw[kc]; j++) {
                jmp[0][kc][i][j] = (jmp[0][kc - 1][i][j] | jmp[0][kc - 1][i][j + lenC]);
            }
        }
    }

    for (int kr = 1; kr < MAXLG; ++kr) {
        int lenR = pw[kr-1];
        if(lenR > n) break;
        for (int kc = 0; kc < MAXLG; ++kc) {
            if(pw[kc] > n) break;
            for (int i = 0; i <= n - pw[kr]; i++) {
                for (int j = 0; j <= n - pw[kc]; j++) {
                    jmp[kr][kc][i][j] = (jmp[kr - 1][kc][i][j] | jmp[kr - 1][kc][i + lenR][j]);
                }
            }
        }
    }
    // end build

    ll tot = 0;

    for(int i = 0; i < n; i++) {
        ll aux = 0;
        for(int j = 0; j < n; j++) {
            int r = n - 1, c = j;

            for(; r >= i; r--) {
                for(; c < n; c++)
                    if(query(i, j, r, c) == bst) break;
                if(c == n) break;
                aux += n - c;
            }
        }
        tot += aux;
    }

    cout << tot << '\n';
}

signed main() {

    lg[1] = 0;
    for(int i = 2; i < MAXN; i++) lg[i] = lg[i/2] + 1;
    for(int i = 0; i < MAXLG; i++) pw[i] = 1 << i;

    solve();
    return 0;
}
