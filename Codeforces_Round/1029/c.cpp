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
    vector<int> a(n + 1);
    vector<queue<int>> fila(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        fila[a[i]].push(i);
    }

    int tot = 0;
    set<int> at; at.insert(a[0]);
    fila[a[0]].pop();
    int pos = 0;
    bool flag = true;

    while(pos < n)
    {
        tot++;
        if (at.empty()) break;
        int newpos = -1;
        for(auto x : at)
        {
            while (!fila[x].empty() && fila[x].front() <= pos)
                fila[x].pop();

            if(fila[x].empty()) 
            {
                flag = false;
                break;
            }
            
            newpos = max(newpos, fila[x].front());
            fila[x].pop();
        }

        if(!flag) break;

        at.clear();

        for(int i = pos + 1; i <= newpos; i++)
            at.insert(a[i]);

        pos = newpos;
    }

    cout << tot << '\n';
}

signed main() { _
    int t; cin >> t; while(t--)
    solve();

    return 0;
}