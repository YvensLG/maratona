#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii; 
typedef vector<int> vi; 

const int MAX = 510;
int ans[MAX][MAX];

void solve(){
    int n, t; cin >> n >> t;
    vi permR(n), permC(n);
    iota(all(permR), 0);
    iota(all(permC), 0);

    while(t--) {
        char c; cin >> c;
        int a, b; cin >> a >> b; a--; b--;
        if(c == 'R') swap(permR[a], permR[b]);
        else swap(permC[a], permC[b]);
    }

    vector<vi> cycR;
    vi mark(n);

    for(int i = 0; i < n; i++) {
        int at = i;
        if(mark[at] != 0) continue;
        cycR.push_back({});
        while(mark[at] == 0) {
            mark[at] = 1;
            cycR.back().push_back(at);
            at = permR[at];
        }
    }

    vector<vi> cycC;
    fill(all(mark), 0);

    for(int i = 0; i < n; i++) {
        int at = i;
        if(mark[at] != 0) continue;
        cycC.push_back({});
        while(mark[at] == 0) {
            mark[at] = 1;
            cycC.back().push_back(at);
            at = permC[at];
        }
    }

    int tam = cycR[0].size();
    for(auto x : cycC) {
        if(tam != x.size()) {
            cout << "*\n";
            return;
        }
    }

    int qtt = cycC.size();

    for (int i = 0; i < qtt; i++) {
        for(int j = 0; j < qtt; j++) {
            int a = (j - i + qtt) % qtt;
            
            for(int k = 0; k < cycC[j].size(); k++) {
                ans[cycR[i][0]][cycC[j][k]] = 1 + a * tam + k; 
            }
            
            for(int l = 1; l < cycR[i].size(); l++) {
                for(int k = 0; k < cycC[j].size(); k++) {
                    ans[cycR[i][l % tam]][cycC[j][k % tam]] = ans[cycR[i][(l - 1 + tam) % tam]][cycC[j][(k - 1 + tam) % tam]];
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}