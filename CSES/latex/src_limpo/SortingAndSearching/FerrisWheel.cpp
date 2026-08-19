const int maxn = 1e5+5, inf = 2e9, M = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    int p[n];

    for(int i=0; i<n; i++) cin >> p[i];
    sort(p, p+n);

    int fim = n-1, inicio = 0, total = n;

    while(fim > inicio){
        if(p[fim] + p[inicio] <= x){
            fim --;
            inicio ++;
            total --;
        }
        else{
            fim --;
        }
    }

    cout << total << '\n';
}
