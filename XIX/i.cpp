#include<bits/stdc++.h>
using namespace std;

const int MAX = 5005;

vector<int> grundy(MAX);

void calc_grundy(){
    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 1;

    vector<int> mex(MAX);
    for(int n = 3; n < MAX; n++) {
        for(int i = 0; i <= n - 2; i++) {
            mex[grundy[(n - 2) - i] ^ grundy[i]] = n; 
        }
        int at = 0;
        for(int i = 0; i <= n; i++) {
            if(mex[i] == n) at = i + 1;
            else break;
        }
        grundy[n] = at;
    }
}

void solve() {
    int n; cin >> n;
    if(grundy[n] > 0) cout << "First\n";
    else cout << "Second\n";
}

signed main(){
    calc_grundy();
    int t; cin >> t; while(t--)
    solve();
}