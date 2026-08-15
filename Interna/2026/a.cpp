#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e6 + 10; 
const int mod = 1e9 + 7; 
const int b1 = 1'000'033; 
const int b2 = 500'000'071;

void solve() {
    int n; cin >> n;
    int at = 0;
    int acc = 0;

    char x; int a, b; 
    cin >> x >> a >> b;

    for(int i = 1; i < n; i++) {
        cin >> x >> a >> b;
        if(x == '-') {
            at = a * 60 + b;
        } 
        else {
            int aux = a * 60 + b;
            acc += aux - at;
            at = aux;
        }
    }

    int fim = 45 * 60 + acc;

    cout << fim / 60 << " minutes " << fim % 60 << " seconds\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 

    solve();

    return 0; 
}
