#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
const int MAX = 1000;
 
int n;
int M[MAX][MAX];
vector<pair<int, int>> horse = {{+1, +2}, {-1, +2}, {+1, -2}, {-1, -2},
                                {+2, +1}, {-2, +1}, {+2, -1}, {-2, -1}};
 
bool check(int x)
{
    return (x >= 0 && x < n);
}
 
void bfs(int a, int b)
{
    M[a][b] = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        for(auto x : horse)
        {
            int x1 = p.first + x.first, y1 = p.second + x.second;
            if(check(x1) && check(y1) && M[x1][y1] == -1)
            {
                q.push({x1, y1});
                M[x1][y1] = M[p.first][p.second] + 1;
            }
        }
    }   
}
 
void solve(){
    cin >> n;
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
           M[i][j] = -1;
        }
    }
 
    bfs(0,0);
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << M[i][j] << ' ';
        }
        cout << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}