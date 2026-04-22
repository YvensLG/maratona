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
    string s; cin >> s;
    s += "      ";
    int n = s.size();
    int tot = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'h' && s[i + 1] == 'a') tot++;
        if(s[i] == 'b' && s[i + 1] == 'o' && s[i + 2] == 'o' && s[i + 3] == 'o' && s[i + 4] == 'o') tot--;
        if(s[i] == 'b' && s[i + 1] == 'r' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'o') tot+=3;
    }

    cout << tot << '\n';
}

signed main() { _
    solve();
    return 0;
}