#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 10, maxpotn = 1030, maxm = 1005, inf = 2e9, M = 1e9 + 7;

/*
complete[n] são todos os possíveis bitsets de "proximos andares" dado que um andar tem n casas vazias
exemplo: se n = 2, podemos completar de 3 possibilidades, {1 1 1}, {1 0 0}, {0 0 1}:
| i | i | i |   | i |   |   |    |   |   | i |
| i | i | i |   | i | - | - |    | - | - | i |
*/
vector<int> complete[maxn + 1];

// dp[n][m] quantidade de formas de fazer m-1 andares completos e o do topo representado pelo bitset n 
ll dp[maxpotn][maxm];

// a transicao[n] são todos os possíveis andares depois de receber um topo com o bitset n
vector<int> transicao[maxpotn];
int n, m; 

// calcula complete
void calcomplete(){
    complete[0].pb(0);
    complete[1].pb(1);
    for(int i = 2; i <= maxn; i++){
        // completa o com i-1 e coloca um dominó em pé
        for(auto x : complete[i - 1]){
            complete[i].pb(x * 2 + 1);
        }
        // completa o com i-2 e coloca um dominó deitado
        for(auto x : complete[i - 2]){
            complete[i].pb(x * 4 + 0);
        }
    }
}

// calcula transicao
void calctransicao(){
    for(int i = 0; i < (1 << n); i++){
        vector<int> v;
        int aux = i;
        int tot = 0;
        // salva seq de 0 e 1 de i
        while(aux != 0){
            int zero = 0;
            while(aux % 2 == 0){
                zero ++;
                aux /= 2;
            }
            v.pb(zero);

            int um = 0;
            while(aux % 2 == 1){
                um ++;
                aux /= 2;
            }
            v.pb(um);
            tot += zero + um;
        }
        // garante n bits
        if(tot != n){
            v.pb(n - tot);
            v.pb(0);
        }

        // fila que guarda as transicoes
        queue<int> fila;
        fila.push(0);

        while(!v.empty()){
            // se estamos em uma seq de 1's o proximo é sempre 0
            int fsz = fila.size();
            for(int j = 0; j < fsz; j++){
                int at = fila.front();
                at = at << v.back();
                fila.push(at);
                fila.pop();
            }
            v.pop_back();

            // em sequencia de 0's, precisamos adicionar os complete
            fsz = fila.size();
            for(int j = 0; j < fsz; j++){
                int at = fila.front();
                at = at << v.back();
                for(auto x : complete[v.back()]){
                    fila.push(at + x);
                }
                fila.pop();
            }
            v.pop_back();
        }

        // salva a fila no vetor transicao
        while(!fila.empty()){
            transicao[i].pb(fila.front());
            fila.pop();
        }
    }
}

void solve() {
    cin >> n >> m;
    calcomplete();
    calctransicao();
    // uma forma do primeiro andar ter 0 dominós
    dp[0][1] = 1;

    // calcula dp
    for(int j = 1; j <= m; j++){
        for(int i = 0; i < (1 << n); i++){
            for(auto x : transicao[i]){
                dp[x][j + 1] = (dp[x][j + 1] + dp[i][j]) % M;
            }
        }
    }

    // quantidade de formas do andar m + 1 ter 0 peças e o resto estar completo
    cout << dp[0][m + 1] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}