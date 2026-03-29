#include<bits/stdc++.h>

using namespace std;

const int N = 2010, V = 510;
array <int, 3> v[N];
int suf[N];
bitset <V*N> dp, fim, ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    int lst = -1;
    for(int i = 0;i < n;i++){
        char c;
        cin >> c;
        cin >> v[i][0];
        if(c == '+')
            v[i][1] = 1;
        string s;
        cin >> s;
        if(s == "async"){
            v[i][2] = 1;
        }
        if(c == '=')
            lst = i;
    }
    for(int i = n-1;i >= 0;i--){
        suf[i] = suf[i+1] + v[i][0];
    }
    vector <int> sc;
    for(int i = 0;i < n;i++){
        if(v[i][2] == 0 and v[i][1] == 1){
            sc.push_back(i);
        }
    }
    dp[0] = true;
    for(int i = 0;i < lst;i++){
        if(v[i][1] == 1 and v[i][2] == 1){
            int w = v[i][0];
            dp = dp | (dp << w);
        }
    }
    if(lst != -1){
        if(v[lst][2] == 0)
            ans |= (dp << suf[lst]);
    }
    sc.push_back(n);
    int at = lst+1;
    for(int j = 0;j < sc.size();j++){
        if(sc[j] < at)
            continue;
        while(at < sc[j]){
            int w = v[at][0];
            dp = dp | (dp << w);
            at++;
        }
        
        fim = fim | (dp << suf[at]);
        at++;
    }
    for(int i = 0;i < n;i++){
        if(v[i][1] == 0 and v[i][2] == 1){
            if(i == n)
                break;
            ans |= (fim << v[i][0]);  
        } 
    }
    if(lst == -1){
        cout << 1 << endl;
        return 0;
    } 
    int res = 0;
    for(int i = 0;i < N*V;i++){
        if(ans[i])
            res++;
    }
    cout << res << '\n';
}