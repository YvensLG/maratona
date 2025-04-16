#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define int long long

vector<int> a;
int n, k;

int pode_formar(int x){
    int total = 0;
    for(auto c : a){
        total += min(c, x);
    }
    return total >= k * x;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    int soma = 0;
    for(int i = 0; i < n; i++) {cin >> a[i]; soma += a[i];}
    
    int l = 0, r = soma / k;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(pode_formar(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

signed main() { _
    solve();
}