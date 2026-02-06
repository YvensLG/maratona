#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<char> big, small;

    for(char x = 'a'; x < 'g'; x++) {
        cout << "? " << x << x << x << endl;
        int a; cin >> a;
        if(a == 1) big.push_back(x);
        else small.push_back(x);
    }

    if(big.size() < 4) big.push_back('g');
    else small.push_back('g');

    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            cout << "? " << small[i] << small[j] << endl;
            int a; cin >> a;
            if(a == 0) swap(small[i], small[j]);
        }
    }

    vector<char> MC, XI;

    for(int i = 0; i < 3; i++) {
        cout << "? " << big[i] << small[0] << endl; 
        int a; cin >> a;
        if(a == 1) MC.push_back(big[i]);
        else XI.push_back(big[i]);
    }

    if(MC.size() < 2) MC.push_back(big[3]);
    else XI.push_back(big[3]);

    int cnt = 0, aux;
    cout << "? " << XI[0] << MC[0] << endl;
    cin >> aux; cnt += aux;
    cout << "? " << XI[0] << MC[1] << endl;
    cin >> aux; cnt += aux;

    char X = XI[0], I = XI[1];
    if(cnt == 0) {
        swap(X, I);
    }

    cout << "? " << X << MC[0] << endl;
    cin >> aux;

    char M = MC[0], C = MC[1];
    if(aux == 1) swap(C, M);

    cout << "! " << M << small[0] << C << small[1] << X << small[2] << I << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}