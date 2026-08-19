bool comp(pii a, pii b){
    if(a.F < b.F) return 1;
    else if(a.F == b.F){
        return a.S > b.S;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    pair<int, int> v[n];
    map<pii, int> mapa;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v[i] = {a, b};
        mapa[v[i]] = i;
    }
    sort(v, v + n, comp);

    ordered_set s1;
    int contido[n];

    for(int i = 0; i < n; i++){
        contido[i] =  i - s1.order_of_key(v[i].second);
        s1.insert(v[i].second);
    }

    ordered_set s2;
    int contem[n];

    for(int i = n - 1; i >= 0; i--){
        contem[i] =  s2.order_of_key(v[i].second + 1);
        s2.insert(v[i].second);
    }

    int transf[n];

    for(int i = 0; i < n; i++){
        transf[mapa[v[i]]] = i;
    }

    for(int i = 0; i < n; i++) cout << contem[transf[i]] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++) cout << contido[transf[i]] << ' ';
    cout << '\n';

}
