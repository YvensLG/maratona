const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

int v[maxn];

int main() {
    string s; cin >> s;
    s.pb('Z');
    int atual = 1, maxi = 0;
    char ant = 'z';

    for(char c : s) {
        if(c == ant) {
            atual ++;
        }
        else {
            ant = c;
            maxi = max(maxi, atual);
            atual = 1;
        }
    }

    cout << maxi << '\n';

    return 0;
}
