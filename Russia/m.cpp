#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define ii pair<int,int>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;


signed main() { _
    // int t; cin >> t; while(t--)
    int n;
    cin>>n;
    vector<pii> v[200001];
    int f[200001];
    int p[200001];
    int mat[200001];
    ll resp=0;
    
    for(int i =1 ; i<=n; i++){
        cin >> f[i];
        mat[i]=-1; 
        }
    for(int i =1 ; i<=n; i++){
        cin >> p[i];
        resp = resp + p[i];
        v[f[i]].push_back({p[i],i});
    }
    vector<int> naousados;
    int usar = 0;
    for(int i =1 ; i<=n; i++){
        if((int)v[i].size()==0 ){
            naousados.push_back(i);
        }
        else{
            sort(v[i].begin(), v[i].end());
            int quem = v[i][(int)v[i].size()-1].second;
            resp = resp -  p[quem];
            mat[quem] = i; //ultimo cara uso no matching e diminuo o valor dele
        }
    }
    
    cout<<resp<<endl;
    for(int i=1;  i<=n; i++){
        if(mat[i]==-1){
            cout<<naousados[usar]<<" ";
            usar++;
        }
        else {
            cout<<mat[i]<<" ";
        }
    }

    return 0;
}