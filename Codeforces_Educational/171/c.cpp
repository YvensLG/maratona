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
	int n; cin >> n;
    string s; cin >> s;
    int at = n - 1;
    int tot = 0;
    queue<int> q;
    while(at >= 0){
        if(s[at] == '1'){
            q.push(at + 1);
        }
        else{
            tot += at + 1;
            if(!q.empty()){
                q.pop();
            }
        }
        at--;
    }
    int meio = (int)q.size() / 2;
    while(meio--) q.pop();

    while(!q.empty()){
        tot += q.front();
        q.pop();
    }

    cout << tot << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}