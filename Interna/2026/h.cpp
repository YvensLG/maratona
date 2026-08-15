#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// hand[jogador][cor][valor] = tem a carta na mão?
bool hand[2][2][2505] = {};
queue<pair<int, int>> deck;

void solve() {
    int n, k; cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int v; char c;
        cin >> v >> c;
        hand[0][c == 'A'][v] = true;
    }

    for (int i = 0; i < k; i++) {
        int v; char c;
        cin >> v >> c;
        hand[1][c == 'A'][v] = true;
    }

    for (int i = 0; i < 2*n - 2*k; i++) {
        int v; char c;
        cin >> v >> c;
        deck.push({c == 'A', v});
    }

    int v = 0, a = 0;
    string ans = "";

    for (int t = 0; t < 2*n; t++) {
        int p = t%2;

        bool can_V = (v < n && hand[p][0][v + 1]);
        bool can_A = (a < n && hand[p][1][a + 1]);

        if (!can_V && !can_A) {
            cout << "-1\n";
            return;
        }

        char at;

        if (can_V && !can_A) at = 'V';
        else if (!can_V && can_A) at = 'A';
        else {
            bool nxt_V = (v + 1 < n && hand[1 - p][0][v + 2]) || (a < n && hand[1 - p][1][a + 1]);

            if (nxt_V) {
                at = 'V';
            } else {
                at = 'A';
            }
        }

        ans += at;
        if (at == 'V') {
            hand[p][0][v + 1] = false; v++;
        } else {
            hand[p][1][a + 1] = false; a++;
        }

        if (!deck.empty()) {
            auto card = deck.front(); deck.pop();
            hand[p][card.first][card.second] = true;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();

    return 0; 
}
