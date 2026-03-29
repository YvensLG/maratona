#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector <int> vals;
    while(n > 0){
        int t = n % 128;
        vals.push_back(t);
        n /= 128;
    }
    reverse(vals.begin(), vals.end());
    for(int i = 0;i < vals.size();i++){
        if(i == vals.size()-1){
            cout << vals[i] << ' ';
        }
        else{
            cout << vals[i] + 128 << ' ';
        }
    }
    cout << '\n';
}