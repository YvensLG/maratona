const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

vector<string> palavras;

void perm(string s, string r){
    if(s == ""){
        palavras.pb(r);
        return;
    }
    int letras[26] = {0};

    for(int i = 0; i < s.size(); i++){
        if(letras[s[i] - 'a'] == 0){
            string copia = s;
            copia.erase(i, 1);
            string dig = "";
            dig += s[i];
            perm(copia, dig + r);
        }
        letras[s[i] - 'a'] ++;
    }
}

void solve(){
    string s; cin >> s;
    perm(s, "");
    cout << palavras.size() << '\n';
    sort(all(palavras));
    for(string s : palavras){
        cout << s << '\n';
    }
}
