const int maxn = 2e6+6, n = 8, m = 64, mod = 1e9+7;

double base[m][m];
vector<pair<int, int>> macaco = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int matriz(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= n) return -1;
    return i*n + j;
}

void mult(double a[m][m], double b[m][m]){
    double c[m][m];

    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            c[i][j] = 0;
            for(int k=0; k<m; k++) c[i][j] += a[i][k] * b[k][j];
        }
    }

    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++)
            a[i][j] = c[i][j];
}

void fexp(double a[m][m], int exp){
    if(exp == 0) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(i == j) a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        return;
    }
    if(exp == 1) return;

    double b[m][m];
    if(exp % 2 == 1)
        for(int i=0; i<m; i++) for(int j=0; j<m; j++) b[i][j] = a[i][j];

    fexp(a, exp / 2);
    mult(a, a);

    if(exp % 2 == 1) mult(a, b);
}

void solve() {
    int k; cin >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bool a = i == 0 || i == n-1;
            bool b = j == 0 || j == n-1;

            if(a && b) {
                for(auto [x, y] : macaco)
                    if(matriz(i+x, j+y) != -1) base[matriz(i, j)][matriz(i+x, j+y)] = (double)1/2;
            }

            else if(a || b) {
                for(auto [x, y] : macaco)
                    if(matriz(i+x, j+y) != -1) base[matriz(i, j)][matriz(i+x, j+y)] = (double)1/3;
            }

            else {
                for(auto [x, y] : macaco)
                    if(matriz(i+x, j+y) != -1) base[matriz(i, j)][matriz(i+x, j+y)] = (double)1/4;
            }
        }
    }

    fexp(base, k);
    double ans = 0;
    for(int j=0; j<m; j++){
        double total = 1;
        for(int i=0; i<m; i++){
            total *= 1 - base[i][j];
        }
        ans += total;
    }

    cout << fixed << setprecision(6);
    cout << ans << '\n';
}
