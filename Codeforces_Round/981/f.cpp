#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000 
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
	ll n, k; cin >> n >> k;
	
    ll f1 = 0, f2 = 1;
    ll pos = 0;

    for(int i = 1; i <= 6 * k + 10; i++){
        ll sum = (f1 + f2) % k;
        f1 = f2;
        f2 = sum;
        if(f1 % k == 0){
            pos = i;
            break;
        }
    }

    cout << (pos * (n % M)) % M << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}