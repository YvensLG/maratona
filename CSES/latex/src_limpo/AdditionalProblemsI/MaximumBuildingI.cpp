const int MAX = 1e3 + 5;

bool M[MAX][MAX];
int v[MAX];

vector<int> next_smaller(int n) {
    vector<int> ans(n + 1, -1), st;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && v[i] < v[st.back()]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}

vector<int> prev_smaller(int n) {
    vector<int> ans(n + 1, -1), st;

    for (int i = n; i >= 0; i--) {
        while (!st.empty() && v[i] < v[st.back()]) {
            ans[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i <= n + 1; i++) {
        M[i][0] = 1;
        M[i][m + 1] = 1;
    }
    for(int j = 0; j <= m + 1; j++) {
        M[0][j] = 1;
        M[n + 1][j] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; cin >> c;
            if(c == '*') M[i][j] = 1;
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        v[0] = -1; v[m + 1] = -1;
        for(int j = 1; j <= m; j++) {
            if(M[i][j]) v[j] = 0;
            else v[j]++;
        }

        auto nxt = next_smaller(m + 1);
        auto prev = prev_smaller(m + 1);

        for(int j = 1; j <= m; j++) {
            int h = v[j], w = nxt[j] - prev[j] - 1;
            ans = max(ans, h * w);
        }
    }

    cout << ans << '\n';
}
