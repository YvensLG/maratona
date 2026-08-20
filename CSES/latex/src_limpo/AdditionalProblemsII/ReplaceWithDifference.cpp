using vi = vector<int>;
using ll = long long;

const int maxn = 1e3 + 10;
const int sqrtn = 40;
const int maxx = sqrtn*maxn;

bool dp[maxn][2*maxx];

void solve(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n; cin >> n;
    vi v(n);
    for( int &x : v ) cin >> x;
    shuffle(all(v), rng);

    dp[0][maxx] = true;
    FOR(i, 1, n + 1){
        FOR(j, 0, 2*maxx){
            if( j - v[i - 1] >= 0 ) dp[i][j] |= dp[i - 1][j - v[i - 1]];
            if( j + v[i - 1] < 2*maxx ) dp[i][j] |= dp[i - 1][j + v[i - 1]];
        }
    }

    if( !dp[n][maxx] ){ cout << -1 << '\n'; return; }

    vi a, b;

    for( int i = n, j = maxx; i >= 1; i-- ){
        if( j - v[i - 1] >= 0 && dp[i - 1][j - v[i - 1]] ){
            a.push_back(v[i - 1]);
            j -= v[i - 1];
        }
        else{
            b.push_back(v[i - 1]);
            j += v[i - 1];
        }
    }

    while( !a.empty() && !b.empty() ){
        cout << a.back() << " " << b.back() << '\n' ;
        int x = min(a.back(), b.back());
        a.back() -= x; b.back() -= x;
        if( !a.back() ) a.pop_back();
        else b.pop_back();
    }
}
