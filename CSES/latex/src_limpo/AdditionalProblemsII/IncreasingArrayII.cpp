void solve(){
    int n; cin >> n;
    priority_queue<int> pq;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        // slope aumenta em 2
        pq.push(x); pq.push(x);
        tot += pq.top() - x;
        pq.pop();
    }
    cout << tot << '\n';
}
