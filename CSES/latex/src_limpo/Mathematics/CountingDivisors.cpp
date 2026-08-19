const int MAX = 1000005;
int divi[MAX];

void calc(){
    divi[0] = 0;
    for(int i=1; i<=MAX; i++){
        for(int j=i; j<=MAX; j+=i){
            divi[j] ++;
        }
    }
}

void solve(){
    int x; cin >> x;
    cout << divi[x] << '\n';
    return;
}

int main(){
    calc();
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
