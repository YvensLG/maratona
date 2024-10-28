#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = LINF + 1;

    while(r - l > 1){
        int k = (l + r) / 2;
        int i = 0, extra = 0;
        while(i < n){
            if(i < n - 1 && a[i + 1] - a[i] <= k){
                i += 2;
            }
            else{
                i ++;
                extra ++;
            }
        }

        if(extra <= 1) r = k;
        else l = k;
    }

    cout << r << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}