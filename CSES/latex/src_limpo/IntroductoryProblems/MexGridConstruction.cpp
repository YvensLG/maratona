void solve(){
    int n; cin >> n;
    int M[n][n];

    vector<vector<bool>> col(n);
    for(int i = 0; i < n; i++)  {
        M[i][0] = M[0][i] = i;
        col[i].resize(2 * n, 0);
        col[i][i] = 1;
    }

    for(int i = 1; i < n; i++) {
        vector<bool> linha(2 * n, 0);
        linha[i] = 1;
        for(int j = 1; j < n; j++) {
            for(int k = 0; k < 2 * n; k++) {
                if(linha[k] == 0 && col[j][k] == 0)  {
                    M[i][j] = k;
                    break;
                }
            }
            col[j][M[i][j]] = true;
            linha[M[i][j]] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << M[i][j] << ' ';
        cout << '\n';
    }
}
