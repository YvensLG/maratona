#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int a,b,c,d;
int l1,l2,r1,r2;
vector<pii> pares;
signed main(){
    cin >> a >> b >> c >> d;
    for(int i = 1;i <= 998;i++){
        for(int j = 1;j <= 998;j++){
            if(__gcd(i , j) == 1 && i + j <= 999){
                pares.push_back({i , j});
            }
        }
    }
    int ans = 0;
    for(auto u : pares){
        int x = u.first, y = u.second;
        l1 = r1 = l2 = r2 = -1;
        l1 = (a + x - 1)/x;
        l2 = b/x;
        r1 = (c + y - 1)/y;
        r2 = d/y;
        int l = max(l1 , r1);
        int r = min(l2 , r2);
        if(r >= l){
            ans += r - l + 1;
        }
    }
    cout << ans << "\n";
}