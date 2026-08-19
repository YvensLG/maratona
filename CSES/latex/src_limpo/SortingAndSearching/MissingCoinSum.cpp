const int MOD = 1e9 + 7, MAX = 1e6 + 5, n = 10;

int32_t main(){
    int n; cin >> n;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p, p + n);

    int at = 1;

    for(int i = 0; i < n; i++){
        if(at >= p[i]) at += p[i];
        else break;
    }

    cout << at << '\n';
}
