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

void solve(){
	
}

signed main() { _
    ll n;
    cin>>n; 
    ll k =0;
    bool sim = false;
    for(ll i=1; i<=n; i++){
        string s;
        cin>>s;
                        sim=true;

        if(s!="?"){
            ll m = stoi(s);
                k =  max(k,i*m - (i)/2);                     
                   }
    }
        if(sim){
        cout<<k<<endl;
        }
        else {
            while(true){
                k++;
            }
        }
    return 0;
}