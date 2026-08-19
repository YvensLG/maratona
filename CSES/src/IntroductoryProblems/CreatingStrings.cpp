#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
 
using namespace std;
 
typedef long long int ll;
 
const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
 
vector<string> palavras;
 
void perm(string s, string r){
    if(s == ""){
        palavras.pb(r);
        return;
    }
    int letras[26] = {0};
 
    for(int i = 0; i < s.size(); i++){
        if(letras[s[i] - 'a'] == 0){
            string copia = s;
            copia.erase(i, 1);
            string dig = "";
            dig += s[i];
            perm(copia, dig + r);
        }
        letras[s[i] - 'a'] ++;
    }
}
 
void solve(){
    string s; cin >> s;
    perm(s, "");
    cout << palavras.size() << '\n';
    sort(all(palavras));
    for(string s : palavras){
        cout << s << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
