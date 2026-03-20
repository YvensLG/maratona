#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 4000;
const int P[] = {71, 73};
const int M[] = {998244353, 1000133333};

string s;
int a[2][N][N];

int ord(char x) {
    if (isupper(x)) {
        return x - 'A' + 1;
    }
    if (islower(x)) {
        return x - 'a' + 27;
    }
    if (isdigit(x)) {
        return x - '0' + 53;
    }
    if (x == '(') {
        return 63;
    }
    if (x == ')') {
        return 64;
    }
    if (x == ' ') {
        return 65;
    }
    return 66;
}

char c[128];

void norm(string& t) {
    for (int i = 'A'; i <= 'Z'; ++i) {
        c[i] = ' ';
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        c[i] = ' ';
    }
    char p = 'A';
    for (int i = 0; i < sz(t); ++i) {
        if (
            isalpha(t[i])
            && (i == 0 || t[i - 1] == ' ')
            && (i == sz(t) - 1 || t[i + 1] == ' ')
        ) {
            if (c[t[i]] == ' ') {
                c[t[i]] = p;
                ++p;
                if (!isalpha(p)) {
                    p = 'a';
                }
            }
            t[i] = c[t[i]];
        }
    }
}

int h[N];
void hsh(string& t, int k) {
    ll p = 1;
    for (int i = 0; i < sz(t); ++i) {
        if (i) {
            h[i] = h[i - 1];
        } else {
            h[i] = 0;
        }
        h[i] = (h[i] + ord(t[i]) * p) % M[k];
        p = p * P[k] % M[k];
    }
}

void read(string& t) {
    int n; cin >> n;
    while (n--) {
        string token; cin >> token;
        t += token;
        t.push_back(' ');
    }
    t.pop_back();
}

void solve() {
    read(s);
    for (int i = 0; i < sz(s); ++i) {
        if (i != 0 && s[i - 1] != ' ') {
            continue;
        }
        string t = s.substr(i);
        norm(t);
        for (int k = 0; k < 2; ++k) {
            hsh(t, k);
            for (int j = 0; j < sz(t); ++j) {
                a[k][i][j] = h[j];
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        string t;
        read(t);
        norm(t);
        hsh(t, 0);
        int h0 = h[sz(t) - 1];
        hsh(t, 1);
        int h1 = h[sz(t) - 1];
        int ans = 0;
        for (int i = 0; i + sz(t) <= sz(s); ++i) {
            if (
                (i == 0 || s[i - 1] == ' ')
                && h0 == a[0][i][sz(t) - 1]
                && h1 == a[1][i][sz(t) - 1]
            ) {
                ans = 1;
                break;
            }
        }
        cout << (ans ? "yes\n" : "no\n");
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}