#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
typedef pair<int, int> pii;
const ll inf=LLONG_MAX;
const int maxn=2010;
    
int matriz[maxn][maxn];
int ans[maxn][maxn];

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);
 
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        string s; cin>> s;
        for(int j=1; j<=m; j++)
            if(s[j-1]=='B')
                matriz[i][j]=1;
    }
    if(n==1 && m!=1)
    {
        for(int j=1; j<=m; j++)
        {
            int q=0;
            if(j==1 || j==m)
                q++;
            if(q%2)
                ans[1][j]=3;
            else
                ans[1][j]=2;
            if(matriz[1][j])
                ans[1][j]=5-ans[1][j];
        } 
    }
    else if(n!=1 && m==1)
    {
        for(int i=1; i<=n; i++)
        {
            int q=0;
            if(i==1 || i==n)
                q++;
            if(q%2)
                ans[i][1]=3;
            else
                ans[i][1]=2;
            if(matriz[i][1])
                ans[i][1]=5-ans[i][1];
        } 
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                int q=0;
                if(i==1 || i==n)
                    q++;
                if(j==1 || j==m)
                    q++;
                if(q%2)
                    ans[i][j]=3;
                else
                    ans[i][j]=2;
                if(matriz[i][j])
                    ans[i][j]=5-ans[i][j];
            }
        }
    }
    cout<< "1\n";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<< ans[i][j];
        cout<< "\n";
    }
 
    return 0;
}   