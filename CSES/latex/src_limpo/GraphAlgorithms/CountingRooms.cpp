const int maxn = 1e3+5, inf = 2e9, M = 1e9 + 7;
const ll linf = 1e18;

char tab[maxn][maxn];
int check[maxn][maxn];
int n, m;

void dfs(int i, int j){
    if(check[i][j] == 0) return;
    check[i][j] = 0;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> tab[i][j];
            if(tab[i][j] == '.') check[i][j] = 1;
        }
    }

    int total = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(check[i][j] == 1){
                total++;
                dfs(i, j);
            }
        }
    }

    cout << total << '\n';
}
