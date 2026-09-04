#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    map<string, pair<int, int>> m;
    string aux; getline(cin, aux);
    for (int i = 0; i < 3 * n; i++) {
        string s; getline(cin, s);

        m[s].second = i;
        m[s].first++;
    }
    vector<pair<pair<int, int>, string>> v;
    for (auto& p: m) v.push_back({p.second, p.first});
    sort(rbegin(v), rend(v));
    for (int i = 0; i < k && i < v.size(); i++) cout << v[i].second << "\n";
}