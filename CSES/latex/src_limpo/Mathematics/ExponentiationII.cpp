int fexp(int a, int b, int M) {
    if (b == 0) return 1;
    int f = fexp(a, b >> 1, M);
    f = ((ll) f * f) % M;
    if (b & 1) f = ((ll) f * a) % M;
    return f;
}

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int p = 1e9 + 7;
    cout << fexp(a, fexp(b, c, p-1), p) << '\n';
}
