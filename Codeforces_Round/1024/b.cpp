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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int A = abs(a[0]);
    int menor = 0, maior = 0;
    for(int i = 1; i < n; i++){
        int v = abs(a[i]);
        if(v < A) menor++;
        else if(v > A) maior++;
    }
    int k = (n + 1) / 2;
    bool ok = false;

    int mn = 1 + menor;
    int mx = mn + maior;
    if(k >= mn && k <= mx) ok = true;

    mn = 1;
    mx = 1 + maior;
    if(k >= mn && k <= mx) ok = true;

    cout << (ok ? "YES\n" : "NO\n");
}

signed main() { _
    int t; 
    cin >> t; 
    while(t--) 
        solve();
    return 0;
}
