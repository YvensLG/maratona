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
typedef long double ld;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n; cin >> n;
    pair<int, int> a[n + 1];
    int pref[n + 1]; pref[0] = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        int v2 = 0;
        while(x % 2 == 0){
            x = x >> 1;
            v2++;
        }
        a[i] = {x, v2};
        pref[i] = pref[i - 1] + x;
    }

    int ant = 0, antv2 = 0, fim = 0;
    int at = 0, atv2 = 0;

    for(int i = 1; i <= n; i++){
        int x = a[i].first, v2 = a[i].second;

        if (pref[i - 1] + x * pow(2, v2 + atv2 + antv2) > at + ant){
            at = pref[i - 1] + x * pow(2, v2 + atv2 + antv2);
            atv2 = v2 + atv2 + antv2; 
            ant = 0;
            antv2 = 0;
            fim = 0;
        }
        else if(pref[i - 1] - pref[fim] + x * pow(2, v2 + atv2) > at){
            at = pref[i - 1] - pref[fim] + x * pow(2, v2 + atv2);
            atv2 += v2;
        }
        else{
            ant += at;
            antv2 += atv2;
            at = x * pow(2, v2); atv2 = v2; 
            fim = i - 1;
        }
        
        cout << (at + ant) % M << ' ';
    }

    cout << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}