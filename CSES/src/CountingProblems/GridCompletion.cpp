#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
#define int long long
 
using namespace std;
 
const int M = 1e9 + 7;
const int MAX = 508;
int fat[MAX], invfat[MAX];

int fexp(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e & 1) ans = ans * b % M;
    return ans;
}
 
int inv(int a) {
    return fexp(a, M - 2);
}
 
int choose(int a, int b) {
    if(b < 0 || b > a) return 0;
    return fat[a] * (invfat[b] * invfat[a - b] % M) % M;
}

/*
 * Solucao: Principio da Inclusao-Exclusao.
 * Universo: Distribuir os As e Bs restantes de forma independente (n - N_A)! * (n - N_B)!
 * PIE: Subtrair as configuracoes invalidas ('A' e 'B' na mesma célula)
 * esse cenario so eh possivel quando:
 *      k1: um novo 'B' cai sobre um 'A' que ja estava fixo no grid (total de c_A opcoes)
 *      k2: um novo 'A' cai sobre um 'B' que ja estava fixo no grid (total de c_B opcoes)
 *      k3: um novo 'A' e um novo 'B' caem juntos em uma celula inicialmente vazia
 * Formula:
 *      F(k3) = sum_{k1=0}^{c_A} (-1)^{k1} * C(c_A, k1) * (n - N_B - k1 - k3)!
 *      G(k3) = sum_{k2=0}^{c_B} (-1)^{k2} * C(c_B, k2) * (n - N_A - k2 - k3)!
 *      Ans   = sum_{k3=0}^{min(r_E, c_E)} (-1)^{k3} * C(r_E, k3) * C(c_E, k3) * k3! * F(k3) * G(k3)
 */
void solve() {
    int n; cin >> n;

    vector<string> grid(n);
    vector<bool> A_row(n, false), A_col(n, false);
    vector<bool> B_row(n, false), B_col(n, false);
    int N_A = 0, N_B = 0;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') {
                A_row[i] = A_col[j] = true;
                N_A++;
            } else if (grid[i][j] == 'B') {
                B_row[i] = B_col[j] = true;
                N_B++;
            }
        }
    }

    int c_A = 0, c_B = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A' && !B_row[i] && !B_col[j]) c_A++;
            if (grid[i][j] == 'B' && !A_row[i] && !A_col[j]) c_B++;
        }
    }

    int r_E = 0, c_E = 0;
    for (int i = 0; i < n; i++) if (!A_row[i] && !B_row[i]) r_E++;
    for (int j = 0; j < n; j++) if (!A_col[j] && !B_col[j]) c_E++;

    int teto = min(r_E, c_E);
    vector<int> F(teto + 1, 0), G(teto + 1, 0);

    for (int k3 = 0; k3 <= teto; k3++) {
        for (int k1 = 0; k1 <= c_A; k1++) {
            int term = choose(c_A, k1) * fat[n - N_B - k1 - k3] % M;
            if (k1 % 2 == 1) F[k3] = (F[k3] - term + M) % M;
            else F[k3] = (F[k3] + term) % M;
        }
        for (int k2 = 0; k2 <= c_B; k2++) {
            int term = choose(c_B, k2) * fat[n - N_A - k2 - k3] % M;
            if (k2 % 2 == 1) G[k3] = (G[k3] - term + M) % M;
            else G[k3] = (G[k3] + term) % M;
        }
    }

    int ans = 0;
    for (int k3 = 0; k3 <= teto; k3++) {
        int term = choose(r_E, k3) * choose(c_E, k3) % M;
        term = term * fat[k3] % M;
        term = term * F[k3] % M;
        term = term * G[k3] % M;

        if (k3 % 2 == 1) ans = (ans - term + M) % M;
        else ans = (ans + term) % M;
    }

    cout << ans << "\n";
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    fat[0] = 1;
    for(int i = 1; i < MAX; i++) fat[i] = (fat[i - 1] * i) % M; 
    invfat[MAX - 1] = inv(fat[MAX - 1]);
    for(int i = MAX - 2; i >= 0; i--) invfat[i] = (invfat[i + 1] * (i + 1)) % M; 
 
    solve();
    return 0;
}