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
    if(n % 4 == 2 || n % 4 == 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> v1;
    vector<int> v2;
    if(n % 4 == 3){
        v1.pb(1); v1.pb(n-1); v2.pb(n);
        for(int i = 2; i <= (n - 1) / 2; i++){
            if(i%2 == 1){
                v1.pb(i); v1.pb(n-i);
            }
            else{
                v2.pb(i); v2.pb(n-i);
            }
        }
    }

    if(n % 4 == 0){
        for(int i = 1; i <= (n) / 2; i++){
            if(i%2 == 1){
                v1.pb(i); v1.pb(n+1-i);
            }
            else{
                v2.pb(i); v2.pb(n+1-i);
            }
        }
    }

    cout << v1.size() << '\n'; printv(v1);
    cout << v2.size() << '\n'; printv(v2);
}
