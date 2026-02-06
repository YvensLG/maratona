#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define INF 1000000000
#define LINF 1000000000000000000LL
#define pb push_back
#define F first
#define S second

// presta atenção nessa linha
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using piii = tuple<int,int,int>;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> b(n);
    for(int &v : b) cin >> v;

    vector<int> a = b;

    vector<piii> op(q);
    for(int i = 0; i < q; i++){
        int x, y, z; cin >> x >> y >> z;
        op[i] = {x - 1, y - 1, z - 1};
    }

    vector<bool> change(n, false);
    bool flag = true;

    for(int i = q - 1; i >= 0; i--){
        int x = get<0>(op[i]), y = get<1>(op[i]), z = get<2>(op[i]);

        if(a[x] < a[z]){
            if(!change[x]) {
                flag = false;
                break;
            }
            a[x] = a[z];
        }

        if(a[y] < a[z]){
            if(!change[y]) {
                flag = false;
                break;
            }
            a[y] = a[z];
        }
        
        if(a[x] != a[z] && a[y] != a[z]){
            flag = false;
            break;
        }
        
        change[z] = true;
    
        if(z == x && a[y] != a[z]) change[z] = false;
        if(z == y && a[x] != a[z]) change[z] = false;
    }

    if(!flag){
        cout << -1 << '\n';
        return;
    }
    
    vector<int> test = a;
    for(int i = 0; i < q; i++){
        int x = get<0>(op[i]), y = get<1>(op[i]), z = get<2>(op[i]);
        test[z] = min(test[x], test[y]);
    }

    if(test != b){
        cout << -1 << '\n';
        return;
    }
    
    for(int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << '\n';

}

signed main(){ _
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
