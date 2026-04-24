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
const int M = 998244353;
const int MAX = 1010;

bool vis[MAX];
int n;
set<pii> edg;
vector<int> deg;

void dfs(int s, int p) {
    vis[s] = 1;
    for(int i = 1; i <= n; i++) {
        if(s == i || p == i) continue;
        if(edg.find({min(i, s), max(i, s)}) != edg.end()) continue;
        if(vis[i]) continue;
        dfs(i, s);
    }
}

bool check_connected() {
    bool flag = true;

    for(int i = 1; i <= n; i++) {
        if(deg[i] != n - 1) {
            dfs(i, 0);
            break;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i] && deg[i] != n - 1) {
            flag = false;
            break;
        }
    }

    return flag;
} 

void solve(){
    cin >> n;
    int p; cin >> p;
    vector<int> l(p);
    for(int i = 0; i < p; i++) cin >> l[i];
    int q; cin >> q;
    vector<int> r(q);
    for(int i = 0; i < q; i++) cin >> r[i];

    if(n == 2) {
        if(p + q > 2) cout << "N\n";
        else if(p == 1 && q == 1) {
            if(l[0] + r[0] == 3) cout << "Y\n";
            else cout << "N\n";
        }
        else if(p == 2) {
            if(l[0] + l[1] == 3) cout << "Y\n";
            else cout << "N\n";
        }
        else if(q == 2) {
            if(r[0] + r[1] == 3) cout << "Y\n";
            else cout << "N\n";
        }
        else {
            cout << "Y\n";
        }
        return;
    }
    else if(n % 2 == 0) {
        cout << "N\n";
        return;
    }

    if(p == 0 && q == 0) {
        cout << "Y\n";
        return;
    }

    deg.resize(n + 1, 0);
    
    for(int i = 1; i < p; i++) {
        deg[l[i]]++; deg[l[i - 1]]++;
        if(l[i] == l[i - 1]) {
            cout << "N\n";
            return;
        }
        edg.insert({min(l[i], l[i-1]), max(l[i], l[i-1])});
    }

    for(int i = 1; i < q; i++) {
        deg[r[i]]++; deg[r[i - 1]]++;
        if(r[i] == r[i - 1]) {
            cout << "N\n";
            return;
        }
        edg.insert({min(r[i], r[i-1]), max(r[i], r[i-1])});
    }

    if(edg.size() != (max(p - 1, 0LL) + max(q - 1, 0LL))) {
        cout << "N\n";
        return;
    }

    if(p > 0 && q > 0 && l[0] != r[q - 1]) {
        cout << "N\n";
        return;
    }

    if(p > 0 && q > 0 && (deg[l[p - 1]] == n - 1 || deg[r[0]] == n - 1)) {
        cout << "N\n";
        return;
    }

    if(!check_connected()) {
        cout << "N\n";
        return;
    }

    int num_1 = 0;
    for(int i = 1; i <= n; i++) if(deg[i] % 2) num_1++;

    if(num_1 > 2 || num_1 == 1) {
        cout << "N\n";
        return;
    }

    if(p > 0 && q > 0) {
        if(deg[l[p - 1]] % 2 && deg[r[0]] % 2 && (l[p - 1] != r[0])) {
            if(num_1 == 2) cout << "Y\n";
            else cout << "N\n";
            return;
        }
        if(!(deg[l[p - 1]] % 2) && !(deg[r[0]] % 2)) {
            if(num_1 == 0 && l[p-1] == r[0]) cout << "Y\n";
            else cout << "N\n";
            return;
        }
        cout << "N\n";
        return;
    }

    if(p == 0) {
        swap(p, q);
        swap(l, r);
        reverse(l.begin(), l.end());
        reverse(r.begin(), r.end());
    }

    if(p == 1) {
        cout << "Y\n";
        return;
    }

    int qntdd = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == n - 1) qntdd++;
    }
    if(qntdd == n) {
        cout << "Y\n";
        return;
    }
    if(deg[l[p - 1]] == n - 1) {
        cout << "N\n";
        return;
    }

    if(num_1 == 2 && deg[l[0]] % 2 && deg[l[p-1]] % 2 && (l[0] != l[p - 1])) {
        cout << "Y\n";
        return;
    }

    if(num_1 == 0 && l[0] == l[p - 1]) {
        cout << "Y\n";
        return;
    }

    cout << "N\n";

}

signed main() { _
    solve();
    return 0;
}