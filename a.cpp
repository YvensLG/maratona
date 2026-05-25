#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1010;
int n, p, s, memo[maxn][3][6], t[3], d[3], inf = 1e9;
 
// cálculo do estado da dp(i, j, k)
// i -> a volta atual em que estamos (de 0 a n)
// j -> o tipo de pneu que estamos usando no momento (0, 1 ou 2)
// k -> a quantidade de pit-stops que já realizamos (0 a S)
int dp(int i, int j, int k) {
    if (i == n) return 0;      // Corrida finalizada com sucesso
    if (memo[i][j][k] != -1)   // Retorna a dp já calculada
		return memo[i][j][k];

	// Se já usou todos os pitstops, checa se é possível terminar
    if (k == s) {
        if (i + d[j] < n) return inf;
        return t[j] * (n - i);
    }

    int ans = inf;

	// Checa se pode ir até o fim com o pneu atual
    if (i + d[j] >= n)
		ans = (n - i) * t[j];
    
	int sum = t[j];

	// Testa todas as voltas possiveis onde podemos fazer o proximo pit-stop
    for (int to = i + 1; to <= min(n, i + d[j]); to++) {
		// Após parar na volta 'to', tentamos seguir com qualquer um dos 3 pneus
        int menor = min({dp(to, 0, k + 1), dp(to, 1, k + 1), dp(to, 2, k + 1)});
        ans = min(ans, sum + menor + p);
        sum += t[j];
    }

	// retornamos e salvamos a melhor resposta
    return memo[i][j][k] = ans;
}
 
int main() {
	// leitura e inicialização da dp
    cin >> n >> p >> s;
    for (int i = 0; i < 3; i++) cin >> t[i];
    for (int i = 0; i < 3; i++) cin >> d[i];
    memset(memo, -1, sizeof(memo));
    int ans = inf;

	// cálculo da dp
    for (int i = 0; i < 3; i++) {
        ans = min(ans, dp(0, i, 0));
    }
    cout << ans << '\n';
}