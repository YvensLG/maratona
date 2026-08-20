using vi = vector<int>;
using pii = pair<int, int>;

array<vi, 2> manacher( const string &s ){
    int n = sz(s);
    array<vi, 2> p = { vi(n + 1), vi(n) };
    FOR(z, 0, 2) for( int i = 0, l = 0, r = 0; i < n; i++ ){
        int t = r - i + !z;
        if(i < r ) p[z][i] = min( t, p[z][l + t] );
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while( L >= 1 && R + 1 < n && s[L - 1] == s[R + 1] )
            p[z][i]++, L--, R++;
        if( R > r ) l = L, r = R;
    }
    return p;
}

void solve(){
    string s; cin >> s;
    auto p = manacher(s);

    int n = sz(s);

    set<int> ids[2];
    vector<vector<pii>> undo(n);

    FOR(i, 0, n){
        if( p[0][i] ){
            ids[0].insert(i);
            undo[i + p[0][i] - 1].push_back({ i, 0 });
        }
        ids[1].insert(i);
        undo[i + p[1][i]].push_back({ i, 1 });

        int ans = 2*(i - *ids[1].begin()) + 1;
        if( !ids[0].empty() ) ans = max( ans, 2*(i - *ids[0].begin() + 1) );

        for( auto [j, t] : undo[i] ) ids[t].erase(j);

        cout << ans << " ";
    }
    cout << '\n';
}
