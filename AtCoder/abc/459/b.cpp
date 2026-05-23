#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        char c = s[0];
        int at = 2;

        if(c > 'c') at++;
        if(c > 'f') at++;
        if(c > 'i') at++;
        if(c > 'l') at++;
        if(c > 'o') at++;
        if(c > 's') at++;
        if(c > 'v') at++;
        if(c > 'z') at++;

        cout << at;
    }
    cout << '\n';

}

signed main() { _
    solve();
}