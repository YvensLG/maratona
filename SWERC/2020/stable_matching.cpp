vector<int> stable_marriage(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size(), b.size();
    assert(a[0].size() == m and b[0].size() == n and n <= m);
    vector<int> match(m, -1), it(n, 0);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
        inv_b[i][b[i][j]] = j;
    
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);
    while (q.size()) {
        int i = q.front(); q.pop();
        int j = a[i][it[i]];

        if (match[j] == -1) match[j] = i;
        else if (inv_b[j][i] < inv_b[j][match[j]]) {
            q.emplace(match[j]);
            it[match[j]]++;
            match[j] = i;
        } else q.emplace(i), it[i]++;
    }
    vector<int> ret(n);
    for (int i = 0; i < m; i++) if (match[i] != -1)
        ret[match[i]] = i;
    return ret;
}