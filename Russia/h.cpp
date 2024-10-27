#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n, a, k, p; cin >> n >> a >> k >> p;
    vector<int> num;
    for(int i = 0; i < n; i++){
        if(num.size() < 5){
            num.pb(a);
        }
        else{
            int minimo = INF;
            int onde = -1;
            for(int i = 0; i < 5; i++){
                if(minimo > num[i]) {
                    minimo = num[i];
                    onde = i;
                }
            }
            if(minimo < a) num[onde] = a;
        }
        a = (a * 1LL * k) % p;
    }

    sort(num.begin(), num.end());

    for(auto x : num) cout << x << ' ';
    cout << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}