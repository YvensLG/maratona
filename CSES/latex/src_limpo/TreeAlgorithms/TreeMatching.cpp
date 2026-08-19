const int MAX = 2e5 + 5;
vi G[MAX];
int dp[MAX][2];

void dfs(int s, int p) {
    for(auto x : G[s]) {
        if(x == p) continue;
        dfs(x, s);
    }
    for(auto x : G[s]) {
        if(x == p) continue;
        dp[s][0] += max(dp[x][0], dp[x][1]);
    }
    for(auto x : G[s]) {
        if(x == p) continue;
        dp[s][1] = max(dp[s][1], 1 + dp[s][0] - max(dp[x][0], dp[x][1]) + dp[x][0]);
    }
}

void solve(){
    int n; cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}
