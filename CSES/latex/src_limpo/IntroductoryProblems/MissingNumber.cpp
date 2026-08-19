const int maxn = 2e5 + 5, inf = 2e9, M = 1e9 + 7;

int v[maxn];

int main() {
    int n; cin >> n;
    v[0] = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[x] = 1;
    }

    for(int i = 0; i <= n; i++){
        if(v[i] != 1) cout << i << '\n';
    }

    return 0;
}
