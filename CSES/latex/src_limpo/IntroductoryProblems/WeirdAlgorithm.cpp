const int maxn = 1010, inf = 2e9, M = 1e9 + 7;

int main() {
    ll n; cin >> n;
    while(n != 1){
        cout << n << ' ';
        if(n % 2 == 0) n = n/2;
        else n = 3*n + 1;
    }
    cout << "1\n";
    return 0;
}
