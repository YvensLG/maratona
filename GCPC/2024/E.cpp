#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX = 302;

// atual, qtt de troca, qtt de nada, qtt de zera
int dp[2][MAX][MAX][MAX];
// 0 -> sempre termina par
// 1 -> sempre termina impar
// 2 -> vc escolhe se cai par ou impar
// -1 -> vc nao tem escolha

void calc(int sa, int sb, int sc) {
    dp[0][0][0][0] = 0;
    dp[1][0][0][0] = 1;

    for(int a = 0; a <= sa; a++) for(int b = 0; b <= sb; b++) for(int c = 0; c <= sc; c++)
    {
        for(int at = 0; at < 2; at++) {
            if(a == 0 && b == 0 && c == 0) continue;
            set<int> aux;
            
            // usa troca
            if(a > 0) aux.insert(dp[1 - at][a - 1][b][c]);
            // usa nada
            if(b > 0) aux.insert(dp[at][a][b - 1][c]);
            // usa zera
            if(c > 0) aux.insert(dp[0][a][b][c - 1]);
    
            if(aux.count(-1) > 0) dp[at][a][b][c] = 2;
            else if(aux.count(0) > 0 && aux.count(1) > 0) dp[at][a][b][c] = 2; 
            else if(aux.count(0) > 0) dp[at][a][b][c] = 0;
            else if(aux.count(1) > 0) dp[at][a][b][c] = 1;
            else dp[at][a][b][c] = -1;
        }
    }
}

void solve() {
    set<pair<char, int>> sa, sb, sc;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char o; int x; cin >> o >> x;
        if(o == '+' && x % 2 == 1) sa.insert({o, x}); // troca
        if(o == '+' && x % 2 == 0) sb.insert({o, x}); // nada
        if(o == '*' && x % 2 == 1) sb.insert({o, x}); // nada
        if(o == '*' && x % 2 == 0) sc.insert({o, x}); // zera
    }
    int x; cin >> x; x = x % 2;
    int a = sa.size(), b = sb.size(), c = sc.size();

    calc(a, b, c);

    int me = 0;
    if(dp[x][a][b][c] >= 1) me = 1;

    if(me == 1) {
        cout << "me" << endl;
        set<int> aux; pair<char, int> rem ;
        if(a > 0 && (dp[1 - x][a - 1][b][c] == 1 || dp[1 - x][a - 1][b][c] == -1)) {
            x = 1 - x; a = a - 1;
            rem = *sa.begin();
            sa.erase(sa.begin());
        }
        else if(b > 0 && (dp[x][a][b - 1][c] == 1 || dp[x][a][b - 1][c] == -1)) {
            b = b - 1;
            rem = *sb.begin();
            sb.erase(sb.begin());
        }
        else if(c > 0 && (dp[0][a][b][c - 1] == 1 || dp[0][a][b][c - 1] == -1)) {
            x = 0; c = c - 1;
            rem = *sc.begin();
            sc.erase(sc.begin());
        }
        cout << rem.first << ' ' << rem.second << endl;
    }
    else {
        cout << "you" << endl;
    }

    while(a > 0 || b > 0 || c > 0) {
        char o; int m; cin >> o >> m;
        if(o == '+' && m % 2 == 1) {sa.erase({o, m}); x = 1 - x;} // troca
        if(o == '+' && m % 2 == 0) {sb.erase({o, m}); x = x;} // nada
        if(o == '*' && m % 2 == 1) {sb.erase({o, m}); x = x;} // nada
        if(o == '*' && m % 2 == 0) {sc.erase({o, m}); x = 0;} // zera
        a = sa.size(); b = sb.size(); c = sc.size();

        pair<char, int> rem ;

        if(a > 0 && (dp[1 - x][a - 1][b][c] == me || dp[1 - x][a - 1][b][c] == -1)) {
            x = 1 - x; a = a - 1;
            rem = *sa.begin();
            sa.erase(sa.begin());
        }
        else if(b > 0 && (dp[x][a][b - 1][c] == me || dp[x][a][b - 1][c] == -1)) {
            b = b - 1;
            rem = *sb.begin();
            sb.erase(sb.begin());
        }
        else if(c > 0 && (dp[0][a][b][c - 1] == me || dp[0][a][b][c - 1] == -1)) {
            x = 0; c = c - 1;
            rem = *sc.begin();
            sc.erase(sc.begin());
        }
        a = sa.size(); b = sb.size(); c = sc.size();
        cout << rem.first << ' ' << rem.second << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
