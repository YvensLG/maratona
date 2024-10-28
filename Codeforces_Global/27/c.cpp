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
    int k = 0;
    int pot = 1;
    while(pot <= n) pot *= 2;
    pot /= 2;

    if(n % 2 == 0){
        int p[n + 1];
        for(int i = 0; i <= n; i++) p[i] = i;
        swap(p[n], p[pot]);
        swap(p[n - 1], p[pot - 1]);
        swap(p[n - 2], p[pot - 2]);
        swap(p[n - 3], p[pot - 3]);
        swap(p[n - 4], p[1]);

        cout << pot * 2 - 1 << '\n';
        for(int i = 1; i <= n; i++){
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    else if(n == 5){
        cout << "5\n2 1 3 4 5\n";
    }
    else{
        int p[n + 1];
        for(int i = 0; i <= n; i++) p[i] = i;
        swap(p[n - 1], p[pot]);
        swap(p[n - 2], p[pot - 1]);
        swap(p[n - 3], p[pot - 2]);
        swap(p[n - 4], p[pot - 3]);
        swap(p[n - 5], p[1]);

        cout << n << '\n';
        for(int i = 1; i <= n; i++){
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}