const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
char tab[10][10];

void damas(int n) {
    int k=0, m = 0, v[n];

    for(int i=0; i<n; i++){
        v[i] = -1;
    }

    while(1){
        v[m]++;

        if(v[m] == n){
            if(m == 0) break;
            v[m] = -1;
            m--;
            continue;
        }
        if(tab[v[m]][m] == '*') continue;

        char a = 0;
        for(int i=0; i<m; i++){
            a = v[m] == v[i];
            a = a || (v[m] == m - i + v[i]);
            a = a || (v[m] == i - m + v[i]);
            if(a){
                break;
            }
        }
        if(a) continue;
        m++;

        if(m == n){
            k++;
            m--;
        }
    }

    printf("%d\n", k);
}

void solve(){
    int n = 8;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tab[i][j];
        }
    }

    damas(n);
}
