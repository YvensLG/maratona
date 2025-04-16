#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long
#define pc  __builtin_popcountll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int sz = 60;
vector<int> ans(sz, -1);
int soma = 0;

void solve() {
    cout << "? 0\n";
    cout.flush();
    int x; cin >> x; 
    soma = pc(x);
    vector<int> lista;
    for(int i = 0; i < sz; i++) lista.push_back(i);
    shuffle(lista.begin(), lista.end(), rng);

    // for(auto x : lista) cout << x << ' ';
    // cout << '\n';

    for(int i = 0; i < sz; i+=2)
    {
        int a = (1LL << lista[i]) + (1LL << lista[i + 1]);
        cout << "? " << a << "\n"; cout.flush();
        cin >> x;
        int novo = pc(x) - soma;

        if(novo == -2)
        {
            ans[lista[i]] = 1;
            ans[lista[i + 1]] = 1;
        }
        else if(novo == 2)
        {
            ans[lista[i]] = 0;
            ans[lista[i + 1]] = 0;
        }
        else 
        {
            int a = (1LL << lista[i]);
            cout << "? " << a << "\n"; cout.flush();
            cin >> x;
            if(pc(x) < soma)
            {
                ans[lista[i]] = 1;
                ans[lista[i + 1]] = 0;
            }
            else
            {
                ans[lista[i]] = 0;
                ans[lista[i + 1]] = 1;
            }
        }
        // for(int i = 0; i < sz; i++) cout << i << ": " << ans[i] << '\n';
    }

    int resp = 0;
    for(int i = 0; i < sz; i++)
    {
        resp += (1LL << i) * ans[i];
    }
    cout << "! " << resp << '\n';
    cout.flush();
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}