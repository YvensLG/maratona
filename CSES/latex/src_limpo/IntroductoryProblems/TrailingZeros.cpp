const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

void printv(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void solve(){
    int n;
    cin >> n;
    int total = 0;
    for(int i = 5; i < M; i *= 5){
        total += n / i;
    }
    cout << total << '\n';
}
