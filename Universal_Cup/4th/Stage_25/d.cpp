#include <bits/stdc++.h>

#define int long long

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e6 + 3;
int n, k;

void mul(vector<int> &v, int a) {
    vector<int> aux = v;

    for(int i = 0; i <= k; i++) aux[i] = aux[i] * a;
    for(int i = 1; i <= k; i++) v[i] = (v[i] + aux[i - 1]) % MOD;
}

void div(vector<int> &v, int a) {
    vector<int> aux;
    reverse(all(v));

    while(v.size()) {
        int v0 = v.back(); v.pop_back();
        aux.push_back(v0);
        if(v.size()) v.back() = (v.back() - v0 * a % MOD + MOD) % MOD;
    }

    swap(aux, v);
}

int eval(vector<int> &v, int a) {
    int pot = 1, ans = 0;

    for(int i = sz(v) - 1; i >= 0; i--) {
        ans = (ans + v[i] * pot) % MOD;
        pot = (pot * a) % MOD;
    }
    
    return ans;
}

void solve_first() {
    cin >> n >> k;
    vector<int> a(n + k);
    vector<int> v(k + 1); v[0] = 1;
    
    for(auto &x : a) {
        cin >> x;
        mul(v, x);
    }

    for(int i = 1; i <= k; i++) cout << v[i] << ' ';
    cout << '\n';
}

void solve_second() {
    cin >> n >> k;
    vector<int> v(k + 1, 1), a(n);
    for(int i = 1; i <= k; i++) cin >> v[i];
    for(auto &x : a) {
        cin >> x;
        div(v, x);
    }

    for(int i = 1; i <= 1e6; i++) {
        if(eval(v, -i) == 0) cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    
    if(s == "first")
        solve_first();
    else 
        solve_second();

    return 0;
}
