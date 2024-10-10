#include <bits/stdc++.h>
#define pb push_back
#define pc __builtin_popcount
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int M = 1e9 + 7;
const int maxn = 55;
const double pi = 3.1415926535897932384626;

#define int long long


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 1){
        vector<int> cntpar1(26), cntimpar1(26);
        vector<int> cntpar2(26), cntimpar2(26);

        for(int i = 2; i < n; i += 2){
            cntpar2[s[i] - 'a'] ++;
        }
        for(int i = 1; i < n; i += 2){
            cntimpar2[s[i] - 'a'] ++;
        }

        int maxpar = 0, maximpar = 0;
        char par, impar;

        for(int i = 0; i < 26; i++){
            maxpar = max(maxpar, cntpar2[i]);
            maximpar = max(maximpar, cntimpar2[i]);
        }

        int maximo = maxpar + maximpar;
        // cout << maximo << '\n';

        for(int i = 1; i < n; i++){
            if(i % 2 == 0){
                cntpar2[s[i] - 'a']--;
                cntpar1[s[i - 1] - 'a']++;
            }
            else{
                cntimpar2[s[i] - 'a']--;
                cntimpar1[s[i - 1] - 'a']++;
            }
            maxpar = 0; maximpar = 0;
            for(int i = 0; i < 26; i++){
                maxpar = max(maxpar, cntpar2[i] + cntpar1[i]);
                maximpar = max(maximpar, cntimpar2[i] + cntimpar1[i]);
            }
            maximo = max(maximo, maxpar + maximpar);
        }

        cout << n - maximo << '\n';
    }
    else{
        vector<int> cntpar(26), cntimpar(26);

        for(int i = 0; i < n; i += 2){
            cntpar[s[i] - 'a'] ++;
        }
        for(int i = 1; i < n; i += 2){
            cntimpar[s[i] - 'a'] ++;
        }

        int maxpar = 0, maximpar = 0;

        for(int i = 0; i < 26; i++){
            maxpar = max(maxpar, cntpar[i]);
            maximpar = max(maximpar, cntimpar[i]);
        }
        
        cout << n - (maxpar + maximpar) << '\n';

    }
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}