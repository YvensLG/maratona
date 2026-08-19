struct res {
    int start1 = -1;
    int dst1 = -1;
    int start2 = -1;
    int dst2 = -1;
};

vector<vector<int>> G;
vector<int> start;
vector<res> ans;
int k, n, m;

// faz uma bfs com todos os inicios e salva os dois melhores (primeiros que aparecem)
void bfs()
{
    ans.resize(n + 1);
    queue<pair<int, int>> fila;

    for(auto x : start) {
        fila.push({x, 1});
        ans[x].start1 = x;
        ans[x].dst1 = 0;
    }

    while(!fila.empty()) {
        auto [at, level] = fila.front(); fila.pop();
        for(auto viz : G[at]) {
            if(ans[viz].start1 == -1 && level == 1) {
                ans[viz].start1 = ans[at].start1;
                ans[viz].dst1 = ans[at].dst1 + 1;
                fila.push({viz, 1});
            }
            else if(ans[viz].start2 == -1) {
                if(ans[at].start1 != ans[viz].start1 && level == 1) {
                    ans[viz].start2 = ans[at].start1;
                    ans[viz].dst2 = ans[at].dst1 + 1;
                    fila.push({viz, 2});
                }
                else if(ans[at].start2 != -1 && level == 2) {
                    ans[viz].start2 = ans[at].start2;
                    ans[viz].dst2 = ans[at].dst2 + 1;
                    fila.push({viz, 2});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    G.resize(n + 1);
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        start.push_back(a);
    }

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs();

    for(int i = 1; i <= n; i++) {
        if(ans[i].dst1 <= 0) cout << ans[i].dst2 << ' ';
        else cout << ans[i].dst1 << ' ';
    }
    cout << '\n';
}
