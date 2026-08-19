const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
int v[26];

void printv(vector<int> &v) {
    for(int i=0; i < v.size(); i++) cout << v[i] << ' ';
    cout << '\n';
}

void solve(){
    string s; cin >> s;
    int a = 0, meio = -1;

    for(char c : s) v[c - 'A']++;

    for(int i=0; i<26; i++) {
        if(v[i] % 2 == 1) {
            a++;
            meio = i;
        }
    }

    s = "";

    if(a >= 2){
        cout << "NO SOLUTION\n";
        return;
    }

    for(int i=0; i<26; i++)
        for(int j = 0; j < v[i]/2; j++)
            s.pb((char) ('A' + i));

    cout << s;
    if(meio != -1) cout << (char) ('A' + meio);
    reverse(s.begin(), s.end());
    cout << s << '\n';
}
