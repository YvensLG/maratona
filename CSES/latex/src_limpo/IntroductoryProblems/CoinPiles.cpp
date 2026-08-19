const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

void printv(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void solve(){
    int a, b;
    cin >> a >> b;
    if((2*b - a) % 3 == 0 && 2*b - a >= 0 && 2*a - b >= 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
