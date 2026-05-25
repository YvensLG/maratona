#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int h, w; cin >> h >> w;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int tot = 0;
            if(i - 1 < 0) tot++;
            if(i + 1 >= h) tot++;
            if(j - 1 < 0) tot++;
            if(j + 1 >= w) tot++;

            cout << 4 - tot << ' ';
        }
        cout << '\n';
    }
}

signed main() { _
    solve();
}