const int n = 7, n2 = 49, inf = 2e9, M = 1e9 + 7;
vector<string> seqs;
string s;

int tab[n+2][n+2], total = 0;

void completar(int x, int y, int soma, char ant){
    if(soma != 1 && s[soma-2] != '?' && s[soma-2] != ant) return;

    int fimh = (tab[x-1][y] == 0) + (tab[x+1][y] == 0);
    int fimv = (tab[x][y-1] == 0) + (tab[x][y+1] == 0);

    if(fimh == 0 && fimv == 2 || fimv == 0 && fimh == 2) return;

    if(x == 1 && y == n && soma != n2) return;
    if(soma == n2){
        total ++;
        //seqs.pb(s);
        return;
    }

    if(fimv + fimh == 0) return;

    if(tab[x-1][y] == 0){
        tab[x-1][y] = 1;
        completar(x-1, y, soma+1, 'L');
        tab[x-1][y] = 0;
    }
    if(tab[x+1][y] == 0){
        tab[x+1][y] = 1;
        completar(x+1, y, soma+1, 'R');
        tab[x+1][y] = 0;
    }
    if(tab[x][y-1] == 0){
        tab[x][y-1] = 1;
        completar(x, y-1, soma+1, 'U');
        tab[x][y-1] = 0;
    }
    if(tab[x][y+1] == 0){
        tab[x][y+1] = 1;
        completar(x, y+1, soma+1, 'D');
        tab[x][y+1] = 0;
    }
}

void solve(){
    tab[1][1] = 1;
    for(int i = 0; i <= n + 1; i ++){
        tab[i][0] = 1;
        tab[i][n+1] = 1;
        tab[0][i] = 1;
        tab[n+1][i] = 1;
    }

    cin >> s;

    completar(1, 1, 1, 'S');

    //sort(all(seqs));
    cout << total << '\n';
}
