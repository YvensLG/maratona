#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main () { _
	int x, n; cin >> x >> n;
 
    set<int> p; p.insert(0); p.insert(x);
    multiset<int> dist; dist.insert(x);
 
    for(int i = 0; i < n; i++){
        int y; cin >> y;
        auto it = p.upper_bound(y);
        int M = *it;
        it --;
        int m = *it;
 
 
        dist.erase(dist.lower_bound(M-m));
 
        dist.insert(M-y);
        dist.insert(y-m);
        
        p.insert(y);
        // for(auto x : dist) cout << x << ' ';
        // cout << '\n';
        cout << *dist.crbegin() << '\n';
    }
 
	return 0;
}