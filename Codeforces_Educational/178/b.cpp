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
    int soma = 0;
    vector<int> a(n); 
    for(int i = 0; i < n; i++){cin >> a[i]; soma += a[i];}
    vector<int> ans(n);
    int maximo = -1;
    ans[0] = soma;
    for(int i = 0; i < n - 1; i++)
    {
        maximo = max(maximo, a[i]);
        soma -= a[i];

        ans[i + 1] = max(soma, soma + maximo - a[i + 1]);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}