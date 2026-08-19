#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;

void solve(){
    int i, j; cin >> i >> j;
    i--; j--;

    int ans = 0;
    if(j <= i / 2)
    {
        ans = (i / 2);
        if(i == 1 && j == 0) 
            ans = (3);

        else if((i % 4 == 1 || i % 4 == 2) && j % 2 == 0)
            ans = (i / 2 + 1);

        else if((i % 4 == 3 || i % 4 == 0) && j % 2 == 1)
            ans = (i / 2 + 1);

        else if(i % 4 == 3 && j % 2 == 0)
            ans = (i / 2 + 2);

        else if(i % 4 == 1 && j % 2 == 1)
            ans = (i / 2 + 2);
    }

    else if(i <= j / 2)
    {
        ans = (j / 2);
        if(j == 1 && i == 0) 
            ans = (3);

        else if((j % 4 == 1 || j % 4 == 2) && i % 2 == 0)
            ans = (j / 2 + 1);

        else if((j % 4 == 3 || j % 4 == 0) && i % 2 == 1)
            ans = (j / 2 + 1);

        else if(j % 4 == 3 && i % 2 == 0)
            ans = (j / 2 + 2);

        else if(j % 4 == 1 && i % 2 == 1)
            ans = (j / 2 + 2);
    }

    else
    {
        ans = ((i + j) / 3);
        if(j == 1 && i == 1) 
            ans = (4);
            
        else if(j == 2 && i == 2) 
            ans = (4);

        else if((i + j) % 3 == 1) 
            ans = ((i + j) / 3 + 1);
            
        else if((i + j) % 3 == 2) 
            ans = ((i + j) / 3 + 2);
    }

    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}