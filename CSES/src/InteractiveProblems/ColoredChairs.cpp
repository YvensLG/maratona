#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
 
char c;
 
// se a gnt tem uma reta: R ? ? ... ? R
// e a qntt de numeros ? é par, sempre há 2 vizinhos de mesma cor
// já se: R ? ? ... ? B
// e a qntt de numeros ? é ímpar, sempre há 2 vizinhos de mesma cor
 
void solveline(int bgn, char cb, int end, char ce) {
    while(true) {
        if(end - bgn <= 1) {
            cout << "! " << bgn << endl;
            return;
        }
 
        int k = (bgn + end) / 2;
    
        cout << "? " << k << endl;
        cin >> c;
        
        if(c == cb) {
            if((k - bgn) % 2 == 1) {
                end = k;
                ce = c;
            } else {
                bgn = k;
                cb = c;
            }
        }
        else {
            if((k - bgn) % 2 == 0) {
                end = k;
                ce = c;
            } else {
                bgn = k;
                cb = c;
            }
        }
    }
}
 
void solvecirc() {
    int n; cin >> n;
    cout << "? " << 1 << endl;
    cin >> c;
 
    solveline(1, c, n + 1, c);
}
 
signed main() { _
    solvecirc();
}