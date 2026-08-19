const int MOD = 1e9 + 7, MAX = 1e6 + 5, n = 10;

int32_t main(){
    int n; cin >> n;
    pair<int, int> p[n + 1];
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    p[n] = {-1, -1};

    int at = 0;

    for(int i = 0; i < n; i++){
        if(p[i].second > p[i+1].second) at++;
    }

    cout << at << '\n';
}
