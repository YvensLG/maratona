using vi = vector<int>;

void fft( vector<C> &a ){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for(static int k = 2; k < n; k *= 2 ){
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L)/k);
        FOR(i, k, 2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }

    vi rev(n);
    FOR(i, 0, n) rev[i] = (rev[i/2] | (i&1) << L )/2;
    FOR(i, 0, n) if( i < rev[i] ) swap( a[i], a[rev[i]] );

    for( int k = 1; k < n; k *= 2 )
        for( int i = 0; i < n; i += 2*k ) FOR(j, 0, k ){
            auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
            C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0] );
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vd conv( const vd &a, const vd &b ){
    if( a.empty() || b.empty() ) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1<<L;
    vector<C> in(n), out(n);
    copy(all(a), in.begin());
    FOR(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for( C& x : in ) x *= x;
    FOR(i, 0, n) out[i] = in[-i&(n - 1)] - conj(in[i]);
    fft(out);
    FOR(i, 0, sz(res)) res[i] = imag(out[i])/(4*n);
    return res;
}

void solve(){
    string s; cin >> s;
    vd a(sz(s));
    FOR(i, 0, sz(s)) a[i] = s[i] - '0';
    vd b(a.rbegin(), a.rend());

    vd ans = conv( a, b );

    for( int i = sz(s); i < sz(ans); i++ ) cout << abs(round(ans[i])) << " "; cout << '\n';
}
