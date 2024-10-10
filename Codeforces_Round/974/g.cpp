#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 2000000000
#define LINF 4000000000000000000 
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 1e6+5;

int vez = 0;

void solve(){
	// n : qtdd de compras
	// m : litros para ficar satisfeito
	// k : validade do leite
	int n, m, k; cin >> n >> m >> k;
	vector<pii> v;

	// v : ordem de dia (d), no dia d, ele compra a litros
	for(int i = 0; i < n; i++){
		int d, a; cin >> d >> a;
		v.push_back({d, a});
	}
	v.push_back({INF, 0});

	// stack que guarda os leites
	stack<pii> stk;

	int cnt = 0;

	for(int i = 0; i < n; i++){
		// olha o período entre uma compra e outra
		int ini = v[i].first;
		int fim = v[i + 1].first - 1;

		// dia atual
		int dat = ini;
		// quantidade atual
		int qat = 0;

		// dia que expira, quantidade
		stk.push({ini + k - 1, v[i].second});
		
		while(!stk.empty()){
			// dia final para essa instância da stack
			int dfim = stk.top().first;
			// quantidade de leite nessa instância da stack
			int qtdd = stk.top().second;

			// se passou da data, trata
			if(dat > dfim){
				stk.pop();
				continue;
			}
			else if(dat > fim){
				break;	
			}

			// quantidade de dias completos
			int c = (qat + qtdd) / m;

			// nao acaba com todo o leite do topo da stack
			if(c >= min(fim, dfim) + 1 - dat){
				c = min(fim, dfim) + 1 - dat;
				stk.top().second -= c * m - qat;
				qat = 0;
			}
			// acaba com o leite
			else{
				stk.top().second = 0;
				qat = (qat + qtdd) - c * m;
			}

			cnt += c;
			dat += c;

			if(stk.top().second <= 0) stk.pop();
		}
	}	

	cout << cnt << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
    int t; cin >> t; while(t--){
		vez++;
    	solve();
	}

    return 0;
}