#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    vector<int> a, b, resp;
    cin >> n;
 
    for(int i=0; i<n; i++){
        a.push_back(i+1);
    }
 
    int i=1; 
    while(a.size()>0){
        if(a.size() == 1){
            resp.push_back(a[0]);
            break;
        }
        for(; i<a.size(); i+=2){
            if(i != 0) b.push_back(a[i-1]);
            resp.push_back(a[i]);
        }
 
        if(i == a.size()){
            b.push_back(a[a.size()-1]);
            i = 0;
        }else{
            i = 1;
        }
        a = b;
        b.clear();
    }
    
    for(int i=0; i<n; i++){
        cout << resp[i] << ' ';
    }
    cout << '\n';
 
    return 0;
}