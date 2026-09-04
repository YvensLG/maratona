#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct UF {
    vector<int> e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    } 
};

void solve(){
    ld x, y; cin >> x >> y;

    int n; cin >> n;
    vector<pair<ld, ld>> arr(n);
    for(auto& u : arr)
        cin >> u.fi >> u.se;
    
    ld l = 0.0, r = 1e7;
    for(int _ = 0; _ < 300; _++){
        ld mid = (l + r) / 2.0;

        UF dsu(n + 4);
        
        for(int i = 0; i < n; i++){
            if(arr[i].fi - mid <= 0.0)
                dsu.join(i + 4, 0);
            if(arr[i].fi + mid >= x)
                dsu.join(i + 4, 2);
            if(arr[i].se - mid <= 0.0)
                dsu.join(i + 4, 1);
            if(arr[i].se + mid >= y)
                dsu.join(i + 4, 3);
            
            for(int j = 0; j < i; j++){
                ld dx = arr[i].fi - arr[j].fi, dy = arr[i].se - arr[j].se;
                dx *= dx; dy *= dy;
                ld dist = sqrt(dx + dy);

                if(dist <= 2 * mid)
                    dsu.join(i + 4, j + 4);
            }
        }

        if(dsu.sameSet(0, 2) || dsu.sameSet(0, 1) || dsu.sameSet(3, 2) || dsu.sameSet(3, 1))
            r = mid;
        else
            l = mid;
    }

    cout.precision(8);
    cout.setf(ios::fixed);

    cout << l << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();
    return 0;
}