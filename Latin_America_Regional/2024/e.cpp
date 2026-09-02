#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep( i, a, b ) for( int i = a; i < (b); i++ )

using ll = long long; 
using pii = pair<int, int>; 
using vi = vector<int>; 

void solve(){
    int n; cin >> n;
    vector<int> v(n + 1), pref(n + 1);

    vector<pii> elem;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        pref[i] = pref[i - 1];
        if(v[i] != 0) {
            elem.push_back({v[i], i});
            pref[i] += 1;
        }
    }
    vector<int> orig = v; 

    if (elem.empty()) {
        for(int i = 1; i <= n; i++) cout << i << ' '; 
        cout << '\n';
        return;
    }

    sort(all(elem));

    int l = 0, r = n + 1;
    int t = 0;

    for(auto [A, pos] : elem) {
        int elem_esq = pref[pos - 1] - pref[l];
        int elem_dir = pref[r - 1] - pref[pos];

        int L_slots = pos - l - 1;
        int R_slots = r - pos - 1;
        int k = A - 1 - t;

        if(elem_esq == 0 && elem_dir == 0) {
            if(L_slots <= k) {
                for(int i = l + 1; i < pos; i++) v[i] = ++t;
                int cur = n;
                for(int i = pos + 1; i < r; i++) {
                    if(cur == A) cur--;
                    v[i] = cur--;
                }
            }
            else if(R_slots <= k) {
                for(int i = r - 1; i > pos; i--) v[i] = ++t;
                int cur = n;
                for(int i = pos - 1; i > l; i--) {
                    if(cur == A) cur--;
                    v[i] = cur--;
                }
            }
            else {
                cout << "*\n";
                return;
            }
        }
        else if(elem_esq == 0) {
            if(L_slots > k) {
                cout << "*\n";
                return;
            }

            for(int i = l + 1; i < pos; i++) v[i] = ++t;
            int rem = k - L_slots;
            for(int i = r - 1; i >= r - rem; i--) v[i] = ++t;
            
            l = pos;
            r = r - rem;
            t = A;
        }
        else if(elem_dir == 0) {
            if(R_slots > k) {
                cout << "*\n";
                return;
            }

            for(int i = r - 1; i > pos; i--) v[i] = ++t;
            int rem = k - R_slots;
            for(int i = l + 1; i <= l + rem; i++) v[i] = ++t;
            
            r = pos;
            l = l + rem;
            t = A;
        }
        else {
            cout << "*\n";
            return;
        }
    }

    bool ok = true;
    int pos_n = max_element(v.begin() + 1, v.end()) - v.begin();

    for(int i = 1; i <= n; i++) {
        if (orig[i] != 0 && orig[i] != v[i]) ok = false; 
        if (i > 1 && i <= pos_n && v[i] <= v[i-1]) ok = false;
        if (i > pos_n && v[i] >= v[i-1]) ok = false;
    }

    if (!ok) {
        cout << "*\n";
        return;
    }

    for(int i = 1; i <= n; i++) cout << v[i] << ' '; cout << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    solve();
}