const int MAX = 5008;
const int MOD = 1e9 + 7;

/*
dp[n][k] = k * dp[n - 1][k] + (n - k + 1) * dp[n - 1][k - 1]
considera o vetor de posicoes, p.ex., [3, 1, 4, 2] -> [2, 4, 1, 3]
o numero de rounds eh o numero de quedas do vetor + 1 (bijecao)
agora queremos adicionar o elemento 'n' no vetor.
Ha 'k' posicoes que nao alteram (finais das rampas)
Ha 'n - k + 1' que alteram (demais posicoes)
*/
int dp[MAX][MAX];

void solve(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for(int j = 2; j <= i; j++) {
            dp[i][j] = ((ll)j * dp[i - 1][j] + ((ll)i - j + 1) * dp[i - 1][j - 1]) % MOD;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[n][i] << ' ';
    }
    cout << '\n';

}
