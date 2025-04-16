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

map<string, int> mapa;
map<char, string> maparev;


string toStr(int n, int base) {
    string convertString = "0123456789ABCDEF";
    if (n < base) {
        return string(1, convertString[n]); 
    } else {
        return toStr(n/base, base) + convertString[n%base];
    }
}

void solve(){
	mapa["la"] = 0;
	mapa["le"] = 1;
	mapa["lon"] = 2;
	mapa["sha"] = 3;
	mapa["she"] = 4;
	mapa["shon"] = 5;
	mapa["ta"] = 6;
	mapa["te"] = 7;
	mapa["ton"] = 8;

    maparev['0'] = "la";
	maparev['1'] = "le";
	maparev['2'] = "lon";
	maparev['3'] = "sha";
	maparev['4'] = "she";
	maparev['5'] = "shon";
	maparev['6'] = "ta";
	maparev['7'] = "te";
	maparev['8'] = "ton";

    string a, b;
    cin >> a >> b;

    a.pop_back(); b.pop_back();

    int A = 0, B = 0;
    string at;

    for(auto x : a)
    {
        at.push_back(x);
        if(mapa.find(at) != mapa.end()){
            A = 9 * A + mapa[at];
            at = "";
        }
    }

    for(auto x : b)
    {
        at.push_back(x);
        if(mapa.find(at) != mapa.end()){
            B = 9 * B + mapa[at];
            at = "";
        }
    }

    string C = toStr(A + B, 9);
    string ans;
    
    for(auto x : C)
    {
        ans.append(maparev[x]);
    }

    ans.push_back('s');

    cout << ans << '\n';

}

signed main() { _
    int t = 1;
    // cin >> t;
    while(t--)
    solve();

    return 0;
}