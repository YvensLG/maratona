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

const int MAX = 4000005;

int q_r[MAX], q_c[MAX], q_d[MAX];
int head = 0, tail = 0;

bool visited[1005][1005][4];
int prev_pd[1005][1005][4];
string grid[1005];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dir_char[4] = {'U', 'D', 'L', 'R'};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W; cin >> H >> W;

    int start_r = -1, start_c = -1;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
        }
    }

    for (int nd = 0; nd < 4; nd++) {
        int nr = start_r + dr[nd];
        int nc = start_c + dc[nd];
        
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != '#') {
            visited[nr][nc][nd] = true;
            prev_pd[nr][nc][nd] = -1;
            q_r[tail] = nr; q_c[tail] = nc; q_d[tail] = nd; tail++;
        }
    }

    while (head < tail) {
        int r = q_r[head];
        int c = q_c[head];
        int d = q_d[head];
        head++;

        if (grid[r][c] == 'G') {
            string ans = "";
            int curr_r = r, curr_c = c, curr_d = d;
            
            while (curr_d != -1) {
                ans += dir_char[curr_d];
                int pd = prev_pd[curr_r][curr_c][curr_d];
                
                curr_r -= dr[curr_d];
                curr_c -= dc[curr_d];
                curr_d = pd;
            }
            
            reverse(ans.begin(), ans.end());
            cout << "Yes\n" << ans << "\n";
            return 0;
        }

        char cell = grid[r][c];
        
        for (int nd = 0; nd < 4; nd++) {
            if (cell == 'o' && nd != d) continue;
            if (cell == 'x' && nd == d) continue;
            
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != '#') {
                if (!visited[nr][nc][nd]) {
                    visited[nr][nc][nd] = true;
                    prev_pd[nr][nc][nd] = d;
                    q_r[tail] = nr; q_c[tail] = nc; q_d[tail] = nd; tail++;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}