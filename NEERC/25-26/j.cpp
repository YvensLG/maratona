#include<bits/stdc++.h>

using namespace std;

void solve(){
    set <string> s1, s2;
    int n;
    cin >> n;
    string anta, antb;
    cin >> anta >> antb;

    bool aux = true;
    for(int i = 1;i < n;i++){
        string a, b;
        cin >> a >> b;
        if(aux and (s1.find(a) != s1.end() or s2.find(b) !=s2.end())){
            cout << "No\n";
            aux = false;
        }
        if(a != anta and b != antb){
            s1.insert(anta);
            s2.insert(antb);
        }
        anta = a;
        antb = b;
    }
    if(aux){
        cout << "Yes\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}