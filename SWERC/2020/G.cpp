#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAX = 1e6 + 1;
const int logMAX = 20;

int n, k;
int divi[MAX];
int prox[MAX];
int pai[MAX];
tuple<ll, ll, ll> calc[MAX];
vector<int> rev[MAX];
bool vis[MAX];

void crivo(int lim) {
    for (int i = 1; i <= lim; i++) divi[i] = 1;

    for(int i = 2; i <= lim; i++)
        for (int j = i; j <= lim; j += i) {
            divi[j]++;
        }
}

void bfs(const vector<int> &cycle) {
    queue<int> q;
    for(int i = 0; i < cycle.size(); i++) {
        vis[cycle[i]] = 1;
        q.push(cycle[i]);
        pai[cycle[i]] = cycle[(i + 1) % cycle.size()];
    }

    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(auto x : rev[at]) {
            if(vis[x]) continue;
            pai[x] = at;
            vis[x] = 1;
            q.push(x);

            if(get<0>(calc[at]) == k) {
                get<0>(calc[x]) = k;
                get<2>(calc[x]) = pai[get<2>(calc[at])];
                get<1>(calc[x]) = get<1>(calc[at]) + x - get<2>(calc[at]);
            }
            else {
                get<0>(calc[x]) = get<0>(calc[at])+1;
                get<2>(calc[x]) = get<2>(calc[at]);
                get<1>(calc[x]) = get<1>(calc[at]) + x;
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    crivo(n);

    for(int i = 0; i < n; i++) {
        prox[i] = (i + divi[i]) % n;
        rev[prox[i]].push_back(i);
    }

    vector<int> search;

    for(int j = 0; j < n; j++) {
        if(vis[j]) continue;
        int tartaruga = j, lebre = j;
    
        do {
            tartaruga = prox[tartaruga];
            lebre = prox[prox[lebre]];
        }
        while (tartaruga != lebre);
    
        vector<int> cycle, todos;
        int at = tartaruga;
        calc[tartaruga] = {0, 0, 0};
        do {
            if(get<0>(calc[tartaruga]) < k) {
                get<0>(calc[tartaruga])++;
                get<1>(calc[tartaruga]) += at;
                get<1>(calc[tartaruga]) = at;
            }

            cycle.push_back(at);
            at = prox[at];
        }
        while(at != tartaruga);

        int prev = tartaruga;
        at = prox[tartaruga];
        while(at != tartaruga) {
            get<0>(calc[at]) = get<0>(calc[prev]);
            get<2>(calc[at]) = prox[get<2>(calc[prev])];
            get<1>(calc[at]) = get<1>(calc[prev]) - prev + get<2>(calc[prev]);
            at = prox[at];
        }
    
        bfs(cycle);
    }

    ll bst = 1e18, pos = -1;

    for(int i = 0; i < n; i++) {
        if(get<0>(calc[i]) == k) {
            if(get<1>(calc[i]) < bst) {
                bst = get<1>(calc[i]);
                pos = i;
            }
        }
    }

    if(pos == -1) cout << -1 << endl;
    else {
        for(int i = 0; i < k; i++) {
            cout << pos << ' '; 
            pos = prox[pos];
        }
        cout << '\n';
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}