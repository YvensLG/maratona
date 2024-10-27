#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;


signed main() { _
    // int t; cin >> t; while(t--)
    ll n, m , k;
    cin>>n>>m>>k;
     
    set<int> colusadas, linusadas;
    map<int, vector<int>> collins, lincols;
    int resp = 0;
    int ptx =0 , pty=0;
    for(int i=1; i<=k; i++){
        int a, b; 
        cin>>a>>b;
        colusadas.insert(a);
        linusadas.insert(b);
        collins[a].push_back(b);
        lincols[b].push_back(a);                
    }
    for(auto &c : colusadas){
        sort(collins[c].begin(), collins[c].end());
        //acho o primeiro diferente de i-1
        if((int)collins[c].size()!=m){
            //entao tem  um util aqui
            int pri =0;
            while(collins[c][pri]==pri+1){
                pri++;
            }
            pri++;
            //pri é uma possivel resp, com resp= pri-1, 
            if((int)collins[c].size()-pri + 1>resp){
                resp = (int)collins[c].size()-pri + 1;
                ptx = c;
                pty = pri;
            }
            int ult = m ;
            while(collins[c][(int)collins.size()-1 -(m-ult)] == ult){
                ult--;
            }
            ult--;
            //pri é uma possivel resp, com resp= pri-1, 
            if((int)collins[c].size()-m+ult>resp){
                resp = (int)collins[c].size()-m+ult;
                ptx = c;
                pty = ult;
            }
            
        }

    }
    for(auto &c : linusadas){
        sort(lincols[c].begin(), lincols[c].end());
        //acho o primeiro diferente de i-1
        if((int)lincols[c].size()!=n){
            //entao tem  um util aqui
            int pri =0;
            while(lincols[c][pri] ==pri+1){
                pri++;
            }
            pri++;
            //pri é uma possivel resp, com resp= pri-1, 
            //nao. Na vdd a resp seria lincols[c].size()-pri
            if((int)lincols[c].size()-pri + 1>resp){
                resp = (int)lincols[c].size()-pri + 1;
                pty = c;
                ptx = pri;
            }
            int ult = n ;
            while(lincols[c][(int)lincols.size()-1 -(n-ult)]==ult){
                ult--;
            }
            ult--;
            //pri é uma possivel resp, com resp= pri-1, 
            if((int)lincols[c].size()-n+ult>resp){
                resp = (int)lincols[c].size() -n + ult;
                pty = c;
                ptx = ult;
            }
            
        }

    }

    
    cout<<resp<<endl;
    cout<<ptx<<" " <<pty<<endl;
    

    return 0;
}