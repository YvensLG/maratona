const int MAXN = 1e6+5;

void solve() {
    int n, x[MAXN];
    for(int i=0; i<MAXN; i++) x[i] = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        x[k] += 1;
    }
    int mdc = 1;

    for(int i = 1; i < MAXN; i++){
        int cont = 0;
        for(int j = i; j < MAXN; j+=i){
            cont += x[j];
            if(cont >= 2) break;
        }
        if(cont >= 2) mdc = i;
    }

    cout << mdc << '\n';
}
