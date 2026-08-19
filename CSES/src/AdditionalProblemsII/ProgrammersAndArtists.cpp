#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
const ll LINF = 4e18;

vector<pair<int, int>> v;
set<pair<int, int>> A, B, difA, difB;

int rem(char x, int pos){
    int s = 0;
    if(x == 'A') {
        A.erase({v[pos].first, pos});
        difA.erase({v[pos].first - v[pos].second, pos});
        s -= v[pos].first;
    }
    if(x == 'B') {
        B.erase({v[pos].second, pos});
        difB.erase({v[pos].second - v[pos].first, pos});
        s -= v[pos].second;
    }
    return s;
}

int add(char x, int pos){
    int s = 0;
    if(x == 'A') {
        A.insert({v[pos].first, pos});
        difA.insert({v[pos].first - v[pos].second, pos});
        s += v[pos].first;
    }
    if(x == 'B') {
        B.insert({v[pos].second, pos});
        difB.insert({v[pos].second - v[pos].first, pos});
        s += v[pos].second;
    }
    return s;
}

void solve(){
    int n, a, b; cin >> a >> b >> n;
    v.resize(n);
    ll s = 0;

    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    for(int i = 0; i < a + b; i++) {
        s += add('A', i);
    }

    for(int i = 0; i < b; i++) { 
        auto it = difA.begin();
        int pos = it -> second;
        s += rem('A', pos);
        s += add('B', pos);
    }

    for(int i = a + b; i < n; i++) {
        ll maxs = 0, s1 = -LINF, s2 = -LINF, s3 = -LINF, s4 = -LINF;
        int posA_rem = -1, posB_rem = -1, posA_swap = -1, posB_swap = -1;

        // add i as a and remove other from a
        if (!A.empty()) {
            posA_rem = A.begin()->second;
            s1 = (ll)v[i].first - v[posA_rem].first;
        }

        // add i as b and remove other from b
        if (!B.empty()) {
            posB_rem = B.begin()->second;
            s2 = (ll)v[i].second - v[posB_rem].second;
        }

        // add i as a , swap some a to b and remove other from b
        if (!A.empty() && !B.empty()) {
            posA_swap = difA.begin()->second;
            posB_rem = B.begin()->second;
            s3 = (ll)v[i].first - v[posA_swap].first + v[posA_swap].second - v[posB_rem].second;
        }

        // add i as b , swap some b to a and remove other from a
        if (!A.empty() && !B.empty()) {
            posB_swap = difB.begin()->second;
            posA_rem = A.begin()->second;
            s4 = (ll)v[i].second - v[posB_swap].second + v[posB_swap].first - v[posA_rem].first;
        }

        maxs = max({0LL, s1, s2, s3, s4});
        s += maxs;

        if(maxs == 0) continue;
        else if(maxs == s1) {
            rem('A', posA_rem);
            add('A', i);
        }else if(maxs == s2) {
            rem('B', posB_rem);
            add('B', i);
        }else if(maxs == s3) {
            rem('A', posA_swap);
            rem('B', posB_rem);
            add('A', i);
            add('B', posA_swap);
        }else if(maxs == s4) {
            rem('B', posB_swap);
            rem('A', posA_rem);
            add('B', i);
            add('A', posB_swap);
        }
    }

    cout << s << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}