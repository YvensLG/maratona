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

const int BLOCK_SIZE = 320;
const int MAXN = 1e5 + 5;

int res[(MAXN / BLOCK_SIZE) + 10][MAXN];

void solve(){
    int n; cin >> n;
    cin.ignore();

    vector<pii> arr(n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        
        int id = 0;
        while(id < (int)s.size()){
            char op = s[id];
            id++;
            
            int curr = 0;
            while(id < (int)s.size() && s[id] != ' '){
                curr *= 10;
                curr += (int)(s[id] - '0');
                id++;
            }

            if(op == '+')
                arr[n - curr - 1].fi = i;
            else
                arr[n - curr - 1].se = i;

            id++;
        }
    }

    for(int block = 0; block * BLOCK_SIZE < n; block++){
        for(int j = block * BLOCK_SIZE; j < min(n, (block + 1) * BLOCK_SIZE); j++){
            res[block][arr[j].fi]++;
            res[block][arr[j].se]--;
        }

        for(int j = 1; j < n; j++)
            res[block][j] += res[block][j - 1];
    }

    int x = 0;
    for(int i = 0; i < n; i++){
        int d; cin >> d;
        d--;

        int lim = n - x;

        int ans = 0, block = 0;
        for(; (block + 1) * BLOCK_SIZE - 1 < lim; block++)
            ans += res[block][d];

        for(int j = block * BLOCK_SIZE; j < lim; j++){
            if(arr[j].fi <= d && arr[j].se > d)
                ans++;
        }

        x = (x + ans) % n;
    }

    cout << x << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while(tt--)
        solve();
    return 0;
}