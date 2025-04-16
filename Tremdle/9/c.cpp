#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

const int MAX = 2000020;
const int MOD = 998244353;
vector<int> f;
vector<int> pot(MAX);

int n, um;
string ans;

int find_one()
{
    int a;
    vector<int> candidates;
    for(int i = 1; i <= n; i++) candidates.push_back(i);
    while(candidates.size() > 1)
    {   
        int x = candidates.back(); candidates.pop_back();
        int y = candidates.back(); candidates.pop_back();
        cout << "? " << x << ' ' << x << ' ' << y << '\n'; cout.flush();
        cin >> ans;
        if(ans == "Yes")
            candidates.push_back(y);
        else
            candidates.push_back(x);
    }
    return candidates[0];
}

bool comparator(int a, int b)
{
    cout << "? " << a << ' ' << um << ' ' << b << '\n'; cout.flush();
    cin >> ans;
    if(ans == "No")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve() {
    cin >> n;
    um = find_one();
    vector<int> lista(n);
    for(int i = 1; i <= n; i++) lista[i - 1] = i;
    stable_sort(lista.begin(), lista.end(), comparator);

    vector<int> p(n+1);
    for(int i = 0; i < n; i++){
        int pos = lista[i];
        p[pos] = i+1;
    }

    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << p[i] << ' ';
    }
    cout << '\n';
}

signed main() { _
    // int t; cin >> t; while(t--)
    solve();
}