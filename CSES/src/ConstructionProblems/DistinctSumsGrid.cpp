#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long int  ll;
typedef vector<int> vi;
typedef vector<vi> graph;

const int MAX = 1024;
int v[MAX][MAX];

int randRange(int hi) {
	return rand() % hi;
}

struct pii {
    int elem;
    int qtt;

    bool operator<(const pii& other) const {
        return elem < other.elem;
    }
};

void adc(set<pii> &sums, int elem, int qtt) {
    auto it = sums.find({elem, 0});
    if(it == sums.end()) {
        if(qtt > 0) sums.insert({elem, qtt});
    }
    else {
        int old_qtt = it -> qtt;
        sums.erase(it);
        if(old_qtt + qtt > 0) sums.insert({elem, old_qtt + qtt});
    }
}

void solve(){
    int n; cin >> n;
    if(n <= 3) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    vector<int> vert(n), hor(n);
    set<pii> sums;
    sums.insert({n * (n + 1) / 2, n});
    for(int i = 0; i < n; i++) {
        sums.insert({n * (i + 1), 1});
        hor[i] = n * (i + 1);
        vert[i] = n * (n + 1) / 2;
        for(int j = 0; j < n; j++) {
            v[i][j] = i + 1;
        }
    }

    while(true) {
        int x1 = randRange(n), y1 = randRange(n);
        int x2 = randRange(n), y2 = randRange(n);
        
        if(n >= 10){
            vector<int> new_elem = {
                hor[x1] + v[x2][y2] - v[x1][y1],
                hor[x2] + v[x1][y1] - v[x2][y2],
                vert[y1] + v[x2][y2] - v[x1][y1],
                vert[y2] + v[x1][y1] - v[x2][y2]
            };

            bool flag = false;
            for(auto x : new_elem) {
                if(sums.find({x, 0}) != sums.end()) flag = true;
            }
            if(flag) continue;
        }

        adc(sums, hor[x1], -1);
        hor[x1] += v[x2][y2] - v[x1][y1];
        adc(sums, hor[x1], +1);
        
        adc(sums, hor[x2], -1);
        hor[x2] += v[x1][y1] - v[x2][y2];
        adc(sums, hor[x2], +1);
        
        adc(sums, vert[y1], -1);
        vert[y1] += v[x2][y2] - v[x1][y1];
        adc(sums, vert[y1], +1);
        
        adc(sums, vert[y2], -1);
        vert[y2] += v[x1][y1] - v[x2][y2];
        adc(sums, vert[y2], +1);

        swap(v[x1][y1], v[x2][y2]);
        if(sums.size() == 2 * n) break;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
