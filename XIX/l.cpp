#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int v[N], h[N];
pair <int, int> resposta[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    int ptr = 1;
    for(int i = 1;i <= n;i++){
        if(ptr == i and i != n){
            int tp = (v[i] <= v[i+1] ? 0 : 1);
            while(ptr < n){
                if(tp == 0){
                    if(v[ptr] <= v[ptr+1]){
                        ptr++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(v[ptr] > v[ptr+1]){
                        ptr++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        h[i] = ptr-i+1;
    }
    int q;
    cin >> q;
    for(int t = 1;t <= n;t++){
        int i = 1;
        int res = 0, bad = 0;
        while(i <= n){
            res++;
            if(h[i] >= t){
                i += h[i];
            }
            else{
                //cout << i << endl;
                if(i+h[i] > n)
                    break;
                bad += min(t - h[i], n - (i + h[i])+1);
                i += t;
            }
        }
        resposta[t] = {res, bad};
    }
    while(q--){
        int t;
        cin >> t;
        cout << resposta[t].first << ' ' << resposta[t].second << '\n';
    }
}