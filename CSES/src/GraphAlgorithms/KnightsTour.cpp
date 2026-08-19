#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

const int MAX = 8;

vector<vector<int>> ans = { {1, 16, 63, 22, 3, 18, 55, 46},
                          {40, 23, 2, 17, 58, 47, 4, 19},
                          {15, 64, 41, 62, 21, 54, 45, 56},
                          {24, 39, 32, 59, 48, 57, 20, 5},
                          {33, 14, 61, 42, 53, 30, 49, 44},
                          {38, 25, 36, 31, 60, 43, 6, 9},
                          {13, 34, 27, 52, 11, 8, 29, 50},
                          {26, 37, 12, 35, 28, 51, 10, 7}};

void solve() {
    int x, y; cin >> y >> x; int at = ans[x - 1][y - 1];

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) cout << (ans[i][j] - at + MAX * MAX) % (MAX * MAX) + 1 << ' ';
        cout << '\n';
    }

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
	return 0;
}


