#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (li.size() <= 1) return;
		int cur = ~li[0];
		for(int i = 2; i < li.size(); i++) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for(int i = 0; i < 2 * N; i++) if (!comp[i]) dfs(i);
		for(int i = 0; i < 1 * N; i++) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void solve(){
    int n, m; cin >> n >> m;
    char M[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> M[i][j];

    TwoSat ts(n * m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i + 1 < n)
            {
                if(M[i][j] == M[i + 1][j])
                {
                    ts.either((i * m + j), ((i + 1) * m + j));
                    ts.either(~(i * m + j), ~((i + 1) * m + j));
                }
                else if(M[i][j] + M[i + 1][j] == 'B' + 'C')
                {
                    ts.either((i * m + j), ((i + 1) * m + j));
                }
                else if(M[i][j] + M[i + 1][j] == 'A' + 'B')
                {
                    ts.either(~(i * m + j), ~((i + 1) * m + j));
                }
                else if(M[i][j] == 'A' && M[i + 1][j] == 'C')
                {
                    ts.either((i * m + j), ~((i + 1) * m + j));
                }
                else
                {
                    ts.either(~(i * m + j), ((i + 1) * m + j));
                }
            }
            
            if(j + 1 < m)
            {
                if(M[i][j] == M[i][j + 1])
                {
                    ts.either((i * m + j), (i * m + (j + 1)));
                    ts.either(~(i * m + j), ~(i * m + (j + 1)));
                }
                else if(M[i][j] + M[i][j + 1] == 'B' + 'C')
                {
                    ts.either((i * m + j), (i * m + (j + 1)));
                }
                else if(M[i][j] + M[i][j + 1] == 'A' + 'B')
                {
                    ts.either(~(i * m + j), ~(i * m + (j + 1)));
                }
                else if(M[i][j] == 'A' && M[i][j + 1] == 'C')
                {
                    ts.either((i * m + j), ~(i * m + (j + 1)));
                }
                else
                {
                    ts.either(~(i * m + j), (i * m + (j + 1)));
                }
            }
        }
    }

    if(!ts.solve())
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int ans = ts.values[i * m + j];
            if(M[i][j] == 'A') cout << "BC"[ans];
            if(M[i][j] == 'B') cout << "AC"[ans];
            if(M[i][j] == 'C') cout << "AB"[ans];
        }
        cout << '\n';
    }
}   
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}