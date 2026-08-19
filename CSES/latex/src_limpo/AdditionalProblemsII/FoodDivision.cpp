void solve(){
    int n; cin >> n;
    vector<int> x(n), y(n), a(n), S(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    for(int i = 1; i < n; i++)
    {
        S[i] = S[i - 1] + y[i] - x[i];
    }

    int ans = 0;
    sort(S.begin(), S.end());
    int median = S[n/2];

    for(int i = 0; i < n; i++)
    {
        ans += abs(median - S[i]);
    }

    cout << ans << '\n';
}
