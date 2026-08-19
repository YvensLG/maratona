void solve(){
    ll n, m; cin >> n >> m;
    vi ans;
    deque<int> list;

    for(int i = 1; i <= n; i++) list.push_back(i);

    for(int i = n; i >= 1; i--) {
        int add = 0;
        if(m >= i - 1) {
            add = list.back(); list.pop_back();
            m -= i - 1;
        }
        else {
            add = list.front(); list.pop_front();
        }
        ans.push_back(add);
    }

    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}
