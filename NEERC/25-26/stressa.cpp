#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <array <int, 3>> v;
    vector <array <int, 3>> ass;
    for(int i = 0;i < n;i++){
        char c;
        cin >> c;
        array <int, 3> eu;        
        if(c == '='){
            eu[0] = 0;
        }
        else{
            eu[0] = 1;
        }
        cin >> eu[1];
        string s;
        cin >> s;
        if(s == "sync"){
            eu[2] = 0;
        }
        else{
            eu[2] = 1;
        }
        v.push_back(eu);
        if(eu[2] == 0)
            ass.push_back(eu);
    }
    set <int> val;
    vector <array <int, 3>> o = v;
    sort(o.begin(), o.end());
    do{ 
        bool aux = true;
        vector <array <int, 3>> p;
        for(int i = 0;i < v.size();i++){
            if(v[i][2] == 0){
                p.push_back(v[i]);
            }
        }
        if(p != ass){
            continue;
        }
        if(aux){
            int res = 0;
            for(int i = 0;i < o.size();i++){
                if(o[i][0] == 0)
                    res = o[i][1];
                else
                    res += o[i][1];
            }
            val.insert(res);
        }

    } while(next_permutation(o.begin(), o.end()));
    cout << val.size() << endl;
}