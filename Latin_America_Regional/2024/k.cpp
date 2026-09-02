#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 
typedef vector<int> vi; 

const ld pi = acos(-1);
const ld INF = 1e18;

void solve(){
    int k; string s;
    cin >> k >> s;
    int n = sz(s);

    if(k == 2) {
        string s1 = "1", s2 = "0";
        int t1 = (s1[0] != s[0]), t2 = (s2[0] != s[0]);
        for(int i = 1; i < n; i++) {
            s1.push_back('1' + '0' - s1.back());
            s2.push_back('1' + '0' - s2.back());
            if(s1[i] != s[i]) t1++;
            if(s2[i] != s[i]) t2++;
        }

        if(t1 < t2) cout << t1 << ' ' << s1 << '\n';
        else cout << t2 << ' ' << s2 << '\n';
        return;
    }

    int consec = 0, troca = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i] == s[i - 1]) consec++;
        else consec = 1;

        if(consec == k) {
            if(i == n - 1 || s[i + 1] == s[i]) s[i] = '1' + '0' - s[i];
            else s[i - 1] = '1' + '0' - s[i - 1];
            troca++;
            consec = 1;
        }
    }

    cout << troca << ' ' << s << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}