const int maxn = 1000005, inf = 2e9, M = 1e9 + 7;
const int dado = 6;

int dp[maxn];

int calc(int n){
    if(n < 0) return 0;
    if(dp[n] != 0) return dp[n];

    for(int i = 1; i <= dado; i++) dp[n] = (dp[n] + calc(n - i)) % M;

    return dp[n] ;
}

void solve() {
    int n; cin >> n;
    dp[0] = 1;
    cout << calc(n) << '\n';
}
