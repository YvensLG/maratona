#include<bits/stdc++.h>
#define int long long 

using namespace std;

map <int, int> m;
vector <pair <int, int>> v;

void backtrack(int n){
    if(m.find(n) != m.end()){
        return;
    }
    int x = n/2;
    if(n % 2 == 0){
        backtrack(x);
        m[n] = v.size();
        v.push_back({m[x], m[x]});
        return;
    }
    else{
        backtrack(x+1);
        backtrack(x);
        m[n] = v.size();
        v.push_back({m[x+1], m[x]});
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    v.push_back({-1, -1});
    m[1] = 0;
    backtrack(n);
    cout << v.size() << '\n';
    for(auto [a, b] : v){
        cout << a << ' ' << b << '\n';
    }
    cout << m[n] << '\n';
    m.clear();
    v.clear();
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}