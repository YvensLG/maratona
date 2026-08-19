const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    int atual = 0, total = 0;

    for(int i=0; i<m; i++){
        if(atual >= n) break;

        if(abs(b[i] - a[atual]) <= k){
            atual ++;
            total ++;
        }
        else if(b[i] - a[atual] > k){
            atual ++;
            i --;
        }
    }

    cout << total << '\n';
}
