// Li Chao tree

const int maxn = 2e5;
const long long INF = 4e18;

ftype dot(point a, point b) {
    return (conj(a) * b).x();
}

ftype f(pair<point, pair<ll, ll>> a,  ftype x) {
    auto p = a.first;
    auto limits = a.second;
    if(x < limits.first || x > limits.second)
        return INF;
    return dot(p, {x, 1});
}

pair<point, pair<ll, ll>> line[4 * maxn];

void gen() {
    for (int i = 0; i < 4 * maxn; i++) {
        line[i] = {{0, INF}, {-INF, INF}};
    }
}

void add_line(pair<point, pair<ll, ll>> nw, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    int L = nw.second.first, R = nw.second.second;

    if (R < l || r <= L) return;

    if (L <= l && r <= R + 1) {
        bool lef = f(nw, l) < f(line[v], l);
        bool mid = f(nw, m) < f(line[v], m);
        if (mid) swap(line[v], nw);

        if (r - l == 1) return;
        if (lef != mid)
            add_line(nw, 2 * v, l, m);
        else
            add_line(nw, 2 * v + 1, m, r);
    } else {
        if (r - l == 1) return;
        add_line(nw, 2 * v, l, m);
        add_line(nw, 2 * v + 1, m, r);
    }
}

ftype get(int x, int v = 1, int l = 0, int r = maxn) {
    int m = (l + r) / 2;
    if(r - l == 1) {
        return f(line[v], x);
    } else if(x < m) {
        return min(f(line[v], x), get(x, 2 * v, l, m));
    } else {
        return min(f(line[v], x), get(x, 2 * v + 1, m, r));
    }
}

void solve() {
    gen();
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        if(q == 1) {
            int a, b; cin >> a >> b;
            int l, r; cin >> l >> r;
            add_line({{-a, -b}, {l, r}});
        }
        else {
            int x; cin >> x;
            ll ans = -get(x);
            if(ans == -INF)
                cout << "NO\n";
            else
                cout << ans << '\n';
        }
    }
}
