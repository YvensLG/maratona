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
	int n; cin >> n;
 
    multiset<int> s;
 
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(s.upper_bound(x) == s.end()) s.insert(x);
        else{
            s.erase(s.upper_bound(x));
            s.insert(x);
        }
    }
        cout << s.size() << '\n';
 
	return 0;
}