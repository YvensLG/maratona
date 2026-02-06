#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

vector<int> primos, prefix = {0};

void listPrime(int n) {
    int limit = 2;
    if (n >= 6) {
        limit = (int)(n * (log(n) + log(log(n))));
    }
    
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= limit && primos.size() < n; ++i) {
        if (is_prime[i]) {
            primos.push_back(i);
        }
    }
}

void calcPrefix()
{
    for(auto x : primos) prefix.push_back(prefix.back() + x);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int soma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        soma += a[i];
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++)
    {
        if(soma >= prefix[n - i]) {
            cout << i << '\n';
            return;
        }
        soma -= a[i];
    }
}

signed main() { _
    listPrime(maxn);
    calcPrefix();
    int t; cin >> t; while(t--)
    solve();

    return 0;
}