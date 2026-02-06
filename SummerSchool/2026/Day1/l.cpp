#include <bits/stdc++.h>

using namespace std;

vector<char> TRANS = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
map<char, string> RETRANS = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};

map<char, char> FLIP = {
    {'0', 'F'},
    {'1', 'E'},
    {'2', 'D'},
    {'3', 'C'},
    {'4', 'B'},
    {'5', 'A'},
    {'6', '9'},
    {'7', '8'},
    {'8', '7'},
    {'9', '6'},
    {'A', '5'},
    {'B', '4'},
    {'C', '3'},
    {'D', '2'},
    {'E', '1'},
    {'F', '0'}
};

void solveE() {
    string s; cin >> s;
    vector<string> bytes(8);
    for(int i = 0; i < 8; i++) {
        bytes[i].push_back(s[2 * i]);
        bytes[i].push_back(s[2 * i + 1]);
    }

    string ans;

    for(auto x : bytes) {
        if(x[1] <= '9' && x[1] % 2 == 0) ans.push_back('0');
        else if(x[1] <= '9') ans.push_back('1');
        else if(x[1] % 2 == 1) ans.push_back('0');
        else ans.push_back('1');
    }

    int part1 = (ans[0] - '0') * 8 + (ans[1] - '0') * 4 + (ans[2] - '0') * 2 + (ans[3] - '0') * 1; 
    int part2 = (ans[4] - '0') * 8 + (ans[5] - '0') * 4 + (ans[6] - '0') * 2 + (ans[7] - '0') * 1; 
    
    cout << s << TRANS[part1] << TRANS[part2] << '\n';
}

void solveD() {
    string s; cin >> s;
    vector<string> bytes(9);
    for(int i = 0; i < 9; i++) {
        bytes[i].push_back(s[2 * i]);
        bytes[i].push_back(s[2 * i + 1]);
    }
    string bans = RETRANS[bytes[8][0]] + RETRANS[bytes[8][1]];
    
    string ans;
    for(auto x : bytes) {
        if(x[1] <= '9' && x[1] % 2 == 0) ans.push_back('0');
        else if(x[1] <= '9') ans.push_back('1');
        else if(x[1] % 2 == 1) ans.push_back('0');
        else ans.push_back('1');
    }

    ans.pop_back();

    int count = 0;
    for(int i = 0; i < 8; i++) {
        if(ans[i] != bans[i]) count ++;
    }

    vector<string> resp(8);

    if(count <= 4) { //ultimo n flipa
        for(int i = 0; i < 8; i++) {
            if(ans[i] != bans[i]) {
                resp[i].push_back(FLIP[bytes[i][0]]);
                resp[i].push_back(FLIP[bytes[i][1]]);
            }
            else {
                resp[i] = bytes[i];
            }
        }
    }
    else { //ultimo flipa
        for(int i = 0; i < 8; i++) {
            if(ans[i] == bans[i]) {
                resp[i].push_back(FLIP[bytes[i][0]]);
                resp[i].push_back(FLIP[bytes[i][1]]);
            }
            else {
                resp[i] = bytes[i];
            }
        }
    }

    for(auto x : resp) cout << x;
    cout << '\n';
}

signed main() {
    int t; cin >> t;
    string s; cin >> s;
    if(s == "encrypt") {
        while(t--) {
            solveE();
        }
    }

    else {
        while(t--) {
            solveD();
        }
    }

    return 0;
}