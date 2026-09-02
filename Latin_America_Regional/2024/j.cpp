#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 
typedef vector<int> vi; 

const ld pi = acos(-1);
const ld INF = 1e18;

void solve(){
    int t, n; cin >> t >> n;
    ld tg = tan(t * pi / 180);
    vector<pair<ld, ld>> rang(n);
    for(int i = 0; i < n; i++) {
        int x, h; cin >> x >> h;
        rang[i] = {x, x + h/tg};
    }
    sort(all(rang));
    rang.push_back({INF, INF});

    ld tot = 0, fim = 0;
    for(int i = 0; i < n; i++) {
        auto [x, y] = rang[i];
        auto [n_x, n_y] = rang[i + 1];

        fim = max(y, fim);

        if(fim > n_x) tot += n_x - x;
        else tot += fim - x;
    }

    cout << setprecision(10) << fixed;
    cout << tot << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}