#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define F first 
#define S second 
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 1050000, maxm = 25, inf = 2e9, M = 1e9 + 7;

// dp[X] = {k, W} -> com o bitset X, k é o menor numero de viagens, W é o peso total da menor viagem
pair<int, int> dp[maxn];
bool tested[maxn];
int pot[maxm];

int cmp(int a, int b)
{
    int count1 = pc(a);
    int count2 = pc(b);
 
    if (count1 <= count2)
        return false;
    return true;
}
 
void solve() {
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    pot[0] = 1;
    for(int i = 1; i < maxm; i++) pot[i] = pot[i - 1] * 2;
    for(int i = 0; i < maxn; i++) dp[i] = {inf, inf};
    dp[0] = {1, 0};

    queue<int> fila;
    fila.push(0);
    tested[0] = true;

    while(!fila.empty()){
        int X = fila.front();
        fila.pop();
        for(int i = 0; i < n; i++){
            int Y = (X | pot[i]);
            if(Y == X) continue;
            if(dp[X].S + w[i] <= x)
                dp[Y] = min(dp[Y], {dp[X].F, dp[X].S + w[i]});
            else
                dp[Y] = min(dp[Y], {dp[X].F + 1, w[i]});

            if(!tested[Y]){
                fila.push(Y);
                tested[Y] = true;
            }
        }
    }

    cout << dp[pot[n] - 1].F << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}