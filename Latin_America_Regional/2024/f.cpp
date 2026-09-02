#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

using ll = long long; 
using pii = pair<int, int>; 
using vi = vector<int>; 

void solve(){
    int n, k; cin >> k >> n;
    int mini = (n + 2) / 3;
    int maxi = (n + 1) / 2;

    if(k > maxi || k < mini) {
        cout << "*\n";
        return;
    }

    vector<int> ans = {0};
    for(int i = 0; i < k - 1; i++) ans.push_back(1);
    ans.push_back(0);
    int at = k + (k - 1);

    for(int i = 0; i < sz(ans); i++, at++) {
        if(at == n) break;
        ans[i]++;
    }

    for(int i = 0; i < sz(ans); i++) {
        for(int j = 0; j < ans[i]; j++) cout << '-';
        if(i != sz(ans) - 1) cout << 'X';
    }
    cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}