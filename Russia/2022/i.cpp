#include <bits/stdc++.h>

using namespace std;

#define int long long

#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)
#define tii tuple<int,int,int,int>
#define pii pair<int,int>
#define ff first
#define ss second
const int maxn = 1e3+5, INF = 1e9;

char mtx[maxn][maxn];
int dist[maxn][maxn][4];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};

// const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

int n,m;

bool valid(int x, int y){
    return x>=0 && y>=0 && x<n && y<m && mtx[x][y] != '#';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int l, r, f, t; cin >> n >> m >> l >> r >> f >> t;
    pii ini;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mtx[i][j];
            if(mtx[i][j] == 'V') ini = {i,j};

            for(int k=0; k<4; k++)
                dist[i][j][k] = INF;
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << mtx[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // return 0;

    dist[ini.ff][ini.ss][0] = 0;
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    pq.push({0, ini.ff, ini.ss, 0});
    while(pq.size()){
        auto[d, x, y, direc] = pq.top(); pq.pop();
        if(dist[x][y][direc] < d) continue;
        // cout << d << " " << dist[x][y][direc] << endl;
        // cout << x << " " << y << " " << direc << endl;
        // cout << endl;

        for(int i=direc; i<direc+4; i++){
            int vx = x+dx[i%4];
            int vy = y+dy[i%4];
            if(valid(vx,vy) && dist[vx][vy][i%4] > dist[x][y][direc] + (i-direc)*r + f){
                dist[vx][vy][i%4] = dist[x][y][direc] + (i-direc)*r + f;
                pq.push({dist[vx][vy][i%4], vx, vy, i%4});
            }
        }

        for(int i=direc-1; i>direc-4; i--){
            int vx = x+dx[(i+4)%4];
            int vy = y+dy[(i+4)%4];
            if(valid(vx,vy) && dist[vx][vy][(i+4)%4] > dist[x][y][direc] + (direc-i)*l + f){
                dist[vx][vy][(i+4)%4] = dist[x][y][direc] + (direc-i)*l + f;
                pq.push({dist[vx][vy][(i+4)%4], vx, vy, (i+4)%4});
            }
        }
    }

    bool ans=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++)
                if(mtx[i][j] == '*' && dist[i][j][k]-f <= t) ans = true;
        }
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}