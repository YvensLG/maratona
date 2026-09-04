#include <bits/stdc++.h>
#define sz(v) ll((v).size())
using namespace std;

using ll = int;
using vl = vector<int>;
using pll = pair<int, int>;

set<ll> stable_marriage(vector<vl> &a, vector<vl> &b, vl &c) {
    int n = a.size(), m = b.size();
    vector<int> it(n, 0);
    vector<priority_queue<pll, vector<pll>, less<>>> match(m);
    vector<unordered_map<int, int>> inv_b(m);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < sz(b[i]); j++)
            inv_b[i][b[i][j]] = j;
    }

    
    queue<int> q;
    for (int i = 0; i < n; i++) q.push(i);
    while (q.size()) {
        int i = q.front(); q.pop();

        if (it[i] == sz(a[i])) continue;

        int j = a[i][it[i]];

        if (sz(match[j]) < c[j]) match[j].push({inv_b[j][i], i});
        else if (inv_b[j][i] < match[j].top().first) {
            q.emplace(match[j].top().second);
            it[match[j].top().second]++;
            match[j].pop();
            match[j].push({inv_b[j][i], i});
        } else q.emplace(i), it[i]++;
    }
    set<ll> ans;
    for (int i = 0; i < m; i++) {
        while (sz(match[i])) {
            // cout << "dbg: " << i + 1 << " " << match[i].top() + 1 << endl;
            ans.insert(match[i].top().second);
            match[i].pop();
        }
    }
    return ans;
}

void read_vector(vl& a) {
    string l; getline(cin, l);
    string aux = "";
    for (auto& c: l) {
        if (c == ' ') {
            a.push_back(stoi(aux) - 1);
            aux = "";
        } else aux += c;
    }
    if(aux == "0")
        return;
    a.push_back(stoi(aux) - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vl> a(n), b(m);
    vl c(m);
    for (int i = 0; i < m; i++) cin >> c[i];

    cin.ignore();
    for (int i = 0; i < n; i++) read_vector(a[i]);
    for (int i = 0; i < m; i++) read_vector(b[i]);

    auto ans = stable_marriage(a, b, c);
    for (ll x: ans) cout << x + 1 << "\n";
}