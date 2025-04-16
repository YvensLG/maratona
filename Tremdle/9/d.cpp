#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

const int MAX = 2000020;
const int MOD = 998244353;
vector<int> f;
vector<int> pot(MAX);

void calcpot()
{
    pot[0] = 1;
    for(int i = 1; i < MAX; i++)
    {
        pot[i] = (pot[i - 1] * 2) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    f.resize(n);
    int ant = -1;
    if(s[0] == '0') f[0] = 1;
    else {
        f[0] = 2;
        ant = 0;
    }

    if(n == 1)
    {
        cout << f[0] << '\n';
        return;
    }

    int i = 1;
    if(ant == -1)
    {
        for(i = 1; i < n; i++)
        {
            if(s[i] == '1') 
            {
                f[i] = (8 * f[i - 1]) % MOD;
                ant = i;
                i++;
                break;
            }
            else
            {
                f[i] = (4 * f[i - 1]) % MOD;
            }
        }
    }

    for(i; i < n; i++)
    {
        if(s[i] == '1')
        {
            if(ant >= 1)
                f[i] = ((pot[2 * (i - ant) + 1] * f[ant]) % MOD - (4 * f[ant - 1]) % MOD + MOD) % MOD;
            else
                f[i] = ((pot[2 * (i - ant) + 1] * f[ant]) % MOD - 1 + MOD) % MOD;
            ant = i;
        }
        else
            f[i] = (4 * f[i - 1]) % MOD;
    }

    cout << f[n - 1] << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    calcpot();
    solve();
}