// NOT FINISHED

bool is_possible(int n, int m, int x1, int y1, int x2, int y2) {
    if (n == 1) return (min(y1, y2) == 0 && max(y1, y2) == m - 1);
    if (m == 1) return (min(x1, x2) == 0 && max(x1, x2) == n - 1);
    int c1 = (x1 + y1) % 2;
    int c2 = (x2 + y2) % 2;
    if ((n * m) % 2 != 0) return c1 == c2 && c1 == 0;
    return c1 != c2;
}

void contra(string &s, char L, char R, char U, char D) {
    reverse(all(s));
    for(int i = 0; i < sz(s); i++) {
        if(s[i] == L) s[i] = R;
        else if(s[i] == R) s[i] = L;
        else if(s[i] == U) s[i] = D;
        else if(s[i] == D) s[i] = U;
    }
}

string solve_from_0(int n, int m, int x, int y, char L, char R, char U, char D) {
    string ans = "";

    if (n == 1) {
        for(int i = 0; i < m - 1; i++) ans += R;
        return ans;
    }
    if (m == 1) {
        for(int i = 0; i < n - 1; i++) ans += D;
        return ans;
    }

    if(n == 2 || m == 2) {
        if(m < n) return solve_from_0(m, n, y, x, U, D, L, R);

        for(int i = 0; i < y; i++) {
            if(i % 2) ans += U;
            else ans += D;

            ans += R;
        }

        if(y % 2) {
            for(int i = y + 1; i < m; i++) ans += R;
            ans += U;
            for(int i = y + 1; i < m; i++) ans += L;
        }
        else {
            for(int i = y + 1; i < m; i++) ans += R;
            ans += D;
            for(int i = y + 1; i < m; i++) ans += L;
        }

        return ans;
    }

    if(x != 0) {
        for(int i = 0; i < m - 1; i++) ans += R;
        ans += D;
        ans += solve_from_0(m, n - 1, (m - 1) - y, x - 1, U, D, R, L);
    }
    else {
        for(int i = 0; i < n - 1; i++) ans += D;
        ans += R;
        ans += solve_from_0(m - 1, n, y - 1, (n - 1) - x, D, U, L, R);
    }
    return ans;
}

string solve_from_any(int n, int m, int x1, int y1, int x2, int y2, char L, char R, char U, char D) {

}

void solve(){
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    if(!is_possible(n,m,x1,y1,x2,y2)) {
        cout << "NO\n";
        return;
    }

    string ans = solve_from_any(n, m, x1, y1, x2, y2, 'L', 'R', 'U', 'D');
    if(sz(ans) == n * m - 1) {
        cout << "YES\n";
        cout << ans << endl;
    }
    else {
        cout << "NO\n";
    }
}
