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
int n, l;
vector<int> x;
queue<pii> q;
set<int> S;

void calc(){
    while(q.size() != 0)
    {
        pii s = q.front();
        q.pop();
        int at = s.second;
        if(s.first >= n) break;
        int y = x[s.first];
        q.push({s.first + 1, at});
        at = at * y;
        while(at <= l + 1)
        {
            if(S.find(at) == S.end())
            {
                S.insert(at);
                q.push({s.first + 1, at});
            }
            at = at * y;
        }
    }
}

void solve(){
    cin >> n >> l;
    vector<int> aux(20);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        aux[a]++;
    } 
    
    for(int i = 0; i < aux.size(); i++)
    {
        if(aux[i] > 0) x.push_back(i + 1);
    }

    n = x.size();
    q.push({0, 1});

    calc();

    cout << S.size() << '\n';
}


signed main() { _
    // int t; cin >> t; while(t--)
    solve();

    return 0;
}