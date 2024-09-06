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
 
void printv (vector<int> v){
    for(int x : v) cout << x << ' ';
    cout << '\n';
}
void printvpii (vector<pii> v){
    for(pii x : v) cout << x.second << " ";
    cout << '\n';
}
 
int main () { _
	int n, m; cin >> n >> m;
    vector<int> v1(n);
    vector<pii> v2(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
        v2[i] = {v1[i], i+1};
    }
    sort(v2.begin(), v2.end());
    v2.pb({-1, -1});
    int total = 0;
    for(int i = 0; i < n; i++)
        if(v2[i+1].S < v2[i].S) total++;
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        int x = v1[a]-1, y = v1[b]-1;
        swap(v1[a], v1[b]);
        if(x > y) swap(x, y);
        total -= (v2[x].second > v2[x+1].second) + (v2[y].second > v2[y+1].second) + (v2[y-1].second > v2[y].second);
        if(x > 0) total -= (v2[x-1].second > v2[x].second);
        if(y == x + 1) total += v2[x].second > v2[y].second;
        swap(v2[x].second, v2[y].second);
        total += (v2[x].second > v2[x+1].second) + (v2[y].second > v2[y+1].second) + (v2[y-1].second > v2[y].second);
        if(x > 0) total += (v2[x-1].second > v2[x].second);
        if(y == x + 1) total -= v2[x].second > v2[y].second;
        cout << total << '\n';
    }
 
	return 0;
}