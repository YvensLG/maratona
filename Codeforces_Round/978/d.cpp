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
	int imp = n;
	for(int i = 1; i <= n / 2; i++){
		int t1 = 2 * i, t2 = 2 * i - 1;
		int t3 = 1;
		if(i == 1) t3 = 3; 

		cout << "? " << t1 << ' ' << t2 << '\n';
		int a; cin >> a;
		cout << "? " << t2 << ' ' << t1 << '\n';
		int b; cin >> b;

		if(a != b){
			if(a == 0) swap(t1, t2); 
			cout << "? " << t3 << ' ' << t1 << '\n';
			int c; cin >> c;
			cout << "? " << t3 << ' ' << t2 << '\n';
			int d; cin >> d;

			if(c == d){
				imp = t2;
			}
			else{
				imp = t1;
			}
			break;
		}
 	}
	cout << "! " << imp << '\n';
	fflush(stdout);
}

int main() {
    int t; cin >> t; while(t--)
    solve();

    return 0;
}