#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i=(a);i<(b);i++)
#define pc(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctzll(x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());
 
const int t = 1000000;
ll v[40], n, full_mask;
pair<ll, ll> aux[t];
 
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
 
    vector<tuple<ll, ll, ll>> prec; 
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ll s = 0;
            for(int k = i; k <= j; k++) s += v[k];
            prec.push_back({s, i, j});
        }
    }
    sort(prec.begin(), prec.end());
    for(int i = 0; i < sz(prec) - 1; i++) {
        if(get<0>(prec[i]) == get<0>(prec[i + 1])) {
            cout << get<2>(prec[i]) - get<1>(prec[i]) + 1 << '\n';
            for(int j = get<1>(prec[i]); j <= get<2>(prec[i]); j++) cout << v[j] << ' ';
            cout << '\n';
 
            cout << get<2>(prec[i + 1]) - get<1>(prec[i + 1]) + 1 << '\n';
            for(int j = get<1>(prec[i + 1]); j <= get<2>(prec[i + 1]); j++) cout << v[j] << ' ';
            cout << '\n';
            return;
        }
    }
 
    full_mask = (1LL << n) - 1LL;
    uniform_int_distribution<ll> uid(1LL, full_mask);
 
    while(true) {
        for(int i = 0; i < t; i++) {
            ll mask = (ll)(uid(rng));
            aux[i] = {0, mask};
 
            while(mask) {
                aux[i].first += v[ctz(mask)];
                mask &= mask - 1;
            }
        }
 
        sort(aux, aux + t);
 
        for(int i = 0; i < t - 1; i++) {
            if(aux[i].first == aux[i + 1].first && aux[i].second != aux[i + 1].second) {
                ll a = aux[i].second;
                ll b = aux[i + 1].second;
    
                ll nd = a & b;
                a ^= nd; b ^= nd;
    
                cout << pc(a) << '\n';
                for(int i = 0; i < n; i++) if(a & (1LL << i)) cout << v[i] << ' ';
                cout << '\n';
    
                cout << pc(b) << '\n';
                for(int i = 0; i < n; i++) if(b & (1LL << i)) cout << v[i] << ' ';
                cout << '\n';
    
                return;
            }
        }
    }
 
}
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}