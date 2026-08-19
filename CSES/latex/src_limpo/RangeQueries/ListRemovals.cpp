template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for(auto &a : x) cin >> a;

    ord_set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);

    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        auto pos = s.find_by_order(p - 1);
        cout << x[*pos] << ' ';
        s.erase(pos);
    }
    cout << '\n';
}
