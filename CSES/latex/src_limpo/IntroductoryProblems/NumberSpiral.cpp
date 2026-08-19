const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

void solve(){
    ll x, y; cin >> y >> x;

    ll a = max(x, y);

    ll resp = (a-1)*(a-1);

    if(a % 2 == 0){
        resp += y + a - x;
    }
    else{
        resp += x + a - y;
    }

    cout << resp << '\n';
}
