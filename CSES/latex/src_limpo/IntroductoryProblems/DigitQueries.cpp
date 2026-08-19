const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;
char tab[10][10];

void solve(){
    ll k, soma = 0;
    cin >> k;
    ll cont = 1, pot = 1, ant = 0;
    while(soma < k){
        ant = soma;
        soma += 9 * pot * cont;
        pot *= 10;
        cont ++;
    }
    ll copia = k;
    ll dig = cont - 1;
    pot /= 10;
    copia -= ant + 1;

    string s = to_string(copia/dig + pot);

    cout << s[copia % dig] << '\n';

}
