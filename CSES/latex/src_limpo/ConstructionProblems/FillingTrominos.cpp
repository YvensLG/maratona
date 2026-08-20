using Matrix = vector<string>;

Matrix transposed( Matrix a ){
    Matrix at(sz(a[0]), string(sz(a), '#'));
    FOR(i, 0, sz(a)) FOR(j, 0, sz(a[0])) at[j][i] = a[i][j];
    return at;
}

Matrix solve( int n, int m, bool corner ){
    if( n <= 0 || m <= 0 ) return Matrix{};
    assert(n > 1 && m > 1);
    if( m%3 != 0 ) return transposed(solve(m, n, false));
    if( n%2 == 0 ){
        Matrix ans;
        for( int i = 0; i < n; i += 4 ){
            ans.emplace_back();
            FOR(j, 0, m/3) ans.back() += "AAB";
            ans.emplace_back();
            FOR(j, 0, m/3) ans.back() += "ABB";

            if( i + 2 == n ) break;

            ans.emplace_back();
            FOR(j, 0, m/3) ans.back() += "BAA";
            ans.emplace_back();
            FOR(j, 0, m/3) ans.back() += "BBA";
        }

        if( corner ) FOR(i, 0, n) FOR(j, 0, m) ans[i][j] += 24;

        return ans;
    }

    if( m%2 == 0 ){
        Matrix ans = solve(n - 3, m, corner);
        FOR(i, 0, 3) ans.emplace_back();

        for( int i = 0; i < m; i += 4 ){
            ans[n - 3] += "CC";
            ans[n - 2] += "CD";
            ans[n - 1] += "DD";

            if( i + 2 == m ) break;

            ans[n - 3] += "DD";
            ans[n - 2] += "CD";
            ans[n - 1] += "CC";
        }
        return ans;
    }

    assert(m >= 9);

    Matrix ans = solve(n - 5, m, false);
    FOR(i, 0, 5) ans.emplace_back();

    Matrix aux = solve(5, m - 9, true);

    ans[n - 5] = "EELLMNNRR" + ((m > 9) ? aux[0] : "");
    ans[n - 4] = "EFLMMNORS" + ((m > 9) ? aux[1] : "");
    ans[n - 3] = "FFHJJOOSS" + ((m > 9) ? aux[2] : "");
    ans[n - 2] = "GHHIJKPQQ" + ((m > 9) ? aux[3] : "");
    ans[n - 1] = "GGIIKKPPQ" + ((m > 9) ? aux[4] : "");

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    if( (n*m)%3 != 0 || n == 1 || m == 1 ){ cout << "NO\n"; return; }
    if( (n == 3 && m%2) || (m == 3 && n%2) ){ cout << "NO\n"; return; }

    cout << "YES\n";
    Matrix ans = solve( n, m, false );

    FOR(i, 0, n){
        FOR(j, 0, m) cout << ans[i][j]; cout << '\n';
    }
}
