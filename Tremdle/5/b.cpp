#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

void solve() {
    int n; cin >> n;
    char M[n][n];
    int soma = 0;
    for(int i = 0; i < n; i++)
    {
        int a = 0;
        for(int j = 0; j < n; j++)
        {
            cin >> M[i][j];
            if(M[i][j] == 'C') a++;
        }
        soma += a * (a - 1) / 2;
    }

    for(int i = 0; i < n; i++)
    {
        int a = 0;
        for(int j = 0; j < n; j++)
        {
            if(M[j][i] == 'C') a++;
        }
        soma += a * (a - 1) / 2;
    }

    cout << soma << '\n';
}

signed main() { _
  solve();
}