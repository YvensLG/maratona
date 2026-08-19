void solve() {
    int n; cin >> n;
    int x, cont = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x % 2 == 1) cont++;
    }

    if(cont > 0) cout << "first\n";
    else cout << "second\n";
}
