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
typedef long double ld;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	
}

signed main() { _
    // int t; cin >> t; while(t--)
    ld a, b, c, d;
    cin>>a>>b>>c>>d;
    //eq1 = dx + csqrt(1-x²) = b
    //eq2 = cx + dsqrt(1-x²) = a
    ld x1=(2*b*d + sqrt((4*b*b*d*d - 4*(b*b - c*c)*(d*d + c*c))))/(2*d*d +2*c*c) ;
    ld x2 =(2*b*d - sqrt((4*b*b*d*d - 4*(b*b - c*c)*(d*d + c*c))))/(2*d*d +2*c*c);
    ld x3=(2*a*d + sqrt((4*a*a*d*d - 4*(a*a - c*c)*(d*d + c*c))))/(2*d*d +2*c*c) ;
    ld  x4 =(2*a*d - sqrt((4*a*a*d*d - 4*(a*a - c*c)*(d*d + c*c))))/(2*d*d +2*c*c);
    if(min(c,d)<= min(a,b) && max(c,d)<=max(a,b)){
        cout<<"Yes"<<endl;
  
    }
    else if(0<=x1 && x1<=1 && c*x1 + d*sqrt(1-x1*x1) <= a ){
        cout<<"Yes"<<endl;
    }    
    else if(0<=x2 && x2<=1 && c*x2 + d*sqrt(1-x2*x2) <= a ){
        cout<<"Yes"<<endl;
    }    
    else if(0<=x3 && x3<=1 && d*x3 + c*sqrt(1-x3*x3) <= b ){
        cout<<"Yes"<<endl;
    }    
    else if(0<=x4 && x4<=1 && d*x4 + c*sqrt(1-x4*x4) <= b ){
        cout<<"Yes"<<endl;
    }    
    else {
        cout<<"No"<<endl;
    }

    return 0;
}