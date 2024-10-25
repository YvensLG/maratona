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
const int inv2 = 5e8 + 4;
const int maxn = 400005;

void solve(){
	int n; cin >> n;
	vector<int> p(n+1), comp(n + 1);
    int tot = 0;

	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

    for(int i = 1; i <= n; i++){
        if(comp[i] == 0){
            comp[i] = i;
            int tam = 1;
            int j = p[i];
            while(j != i){
                comp[j] = comp[i];
                j = p[j];
                tam++;
            }
            tot += (tam - 1) / 2;
        }
    }

    // for(int i = 0; i <= n; i++) cout << comp[i] << ' ';
    // cout << '\n';


    cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while(t--)
    solve();

    return 0;
}