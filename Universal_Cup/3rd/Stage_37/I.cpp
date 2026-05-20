#include <bits/stdc++.h>
using namespace std; 

const int inf = 2e9; 

using ll = long long;

void solve(){
    int n, k; cin >> n >> k;
    if( !(n <= k && k <= n * n - (n - 1)) ) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<int> use;
    for(int i = n; i <= n * n; i++)  {
        if(i < k || i > k + (n - 1))
            use.push_back(i);
    }

    cout << k << ' ';
    for(int i = 1; i < n; i++) {
        cout << i << ' ';
    }
    cout << '\n';
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) cout << k + i << ' ';
            else {
                cout << use.back() << ' ';
                use.pop_back();
            }
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t; 
    while( t-- ) solve(); 
}