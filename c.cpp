#include <bits/stdc++.h>

using namespace std;



#define F first

#define S second



typedef pair<int, int> pii;



const int MAX = 25'000'000;



bool grid[MAX], art[MAX];

int tin[MAX], low[MAX];



int stk_u[MAX];

int stk_c[MAX];

int stk_p_edge[MAX];



int n, m, timer = 1, ans = 0;



void dfs(int s) {

    int adj[4] = {1, -1, m, -m};    

    

    int top = 0, tot = n * m, children = 0;

    stk_u[top] = s;

    stk_c[top] = s % m;

    stk_p_edge[top] = (-1 << 3) | 0;



    tin[s] = low[s] = timer++;



    while(top >= 0) {

        int u = stk_u[top], col = stk_c[top];



        int p = stk_p_edge[top] >> 3;

        int edge = stk_p_edge[top] & 7;



        if (edge == 4) {

            top--;

            

            if (p == -1) { 

                if (children > 1 && !art[u]) {

                    art[u] = true;

                    ans++;

                }

            } else { 

                low[p] = min(low[p], low[u]);

                if (low[u] >= tin[p] && tin[p] > 1 && !art[p]) {

                    art[p] = true;

                    ans++;

                }

            }

            continue;

        }



        stk_p_edge[top]++;

        int v = u + adj[edge];



        if (edge == 0 && (col == m - 1)) continue;

        if (edge == 1 && (col == 0)) continue;

        if (v < 0 || v >= tot || grid[v] || v == p) continue;



        if (tin[v]) {

            if (tin[v] < low[u]) low[u] = tin[v];

        } else {

            if (p == -1) children++;

            tin[v] = low[v] = timer++;

            

            top++;

            stk_u[top] = v;

            stk_p_edge[top] = (u << 3) | 0;



            if (edge == 0) stk_c[top] = col + 1;

            else if (edge == 1) stk_c[top] = col - 1;

            else stk_c[top] = col;

        }

    }

}



void solve() {

    cin >> n >> m;



    string s;

    int srt = -1;

    for (int i = 0; i < n; i++) {

        cin >> s;

        int col = 0;



        for (char c : s) {

            int val = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;



            for (int bit = 3; bit >= 0; bit--) {

                if (col < m) {

                    int u = i * m + col; 

                    grid[u] = (val >> bit) & 1;

                    

                    if (!grid[u] && srt == -1) srt = u;

                    col++;

                }

            }

        }

    }



    if(srt != -1) dfs(srt);



    cout << ans << '\n';

}

 

signed main() {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();

    return 0;

}