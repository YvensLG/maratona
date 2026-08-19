vector<vector<char>> M;
int n;

void solve() {
    cin >> n;
    M.resize(n + 1, vector<char>(n + 1));

    for(int i = 0; i <= n; i++) M[i][0] = '$';
    for(int i = 0; i <= n; i++) M[0][i] = '$';

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> M[i][j];

    string s; s.push_back(M[1][1]);
    for(int sum = 3; sum <= 2 * n; sum++)
    {
        char best = 'Z';
        for(int i = max(1, sum - n); i <= min(n, sum - 1); i++)
        {
            int j = sum - i;
            if(M[i - 1][j] != '$') best = min(best, M[i][j]);
            if(M[i][j - 1] != '$') best = min(best, M[i][j]);
        }

        s.push_back(best);
        for(int i = max(1, sum - n); i <= min(n, sum - 1); i++)
        {
            int j = sum - i;
            if(M[i - 1][j] == '$' && M[i][j - 1] == '$' || M[i][j] != best) M[i][j] = '$';
        }
    }

    cout << s << '\n';
}
