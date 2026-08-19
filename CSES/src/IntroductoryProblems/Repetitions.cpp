#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
int v[maxn];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while (t--)
    string s; cin >> s;
    s.pb('Z');
    int atual = 1, maxi = 0;
    char ant = 'z';
 
    for(char c : s){
        if(c == ant){
            atual ++;
        }
        else{
            ant = c;
            maxi = max(maxi, atual);
            atual = 1;
        }
    }
 
    cout << maxi << '\n';
 
    return 0;
}
