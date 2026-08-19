const int maxn = 2e6+5;
int v[maxn];

int main() {
    ios::sync_with_stdio(0), cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> p(k);
    for(int i = 0; i < k; i ++) cin >> p[i];

    for(int i = 0; i <= n; i++){
        if(v[i] == 0){
            for(int j = 0; j < k; j++){
                v[i + p[j]] = 1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(v[i] == 0) cout << "L";
        else cout << "W";
    }
    cout << '\n';

    return 0;
}
