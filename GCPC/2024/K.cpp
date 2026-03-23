#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int inv = 0;
    string bdpq = "bdpq";

    for(auto x : t) {
        if(x == 'h' || x == 'r') inv = 1 - inv;
        for(int i = 0; i < 4; i++) {
            char c = bdpq[i];
            if(x == 'h') {
                if(c == 'p' || c == 'q') c = 'p' + 'q' - c;
                else if(c == 'b' || c == 'd') c = 'b' + 'd' - c;
            }
            if(x == 'v') {
                if(c == 'b' || c == 'p') c = 'b' + 'p' - c;
                else if(c == 'q' || c == 'd') c = 'q' + 'd' - c;
            }
            if(x == 'r') {
                if(c == 'b' || c == 'q') c = 'b' + 'q' - c;
                else if(c == 'd' || c == 'p') c = 'd' + 'p' - c;
            }
            bdpq[i] = c;
        }
    }

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'b') s[i] = bdpq[0];
        else if(s[i] == 'd') s[i] = bdpq[1];
        else if(s[i] == 'p') s[i] = bdpq[2];
        else if(s[i] == 'q') s[i] = bdpq[3];
    }

    if(inv) reverse(s.begin(), s.end());

    cout << s << '\n';
}