#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define pb push_back
#define ll long long int
#define int long long
const int MOD = 1e9 + 7, MAX = 1e6 + 5, n = 10;
 
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    pair<int, int> p[n + 1];
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n);
    p[n] = {-1, -1};
 
    int at = 0;
 
    for(int i = 0; i < n; i++){
        if(p[i].second > p[i+1].second) at++;
    }
 
    cout << at << '\n';
}