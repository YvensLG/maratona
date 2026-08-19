vector<double> Prod(vector<double>& a, vector<double>& b) {
    vector<double> c (a.size() + b.size() - 1);
    for(int i = 0; i < c.size(); i++){
        c[i] = 0;
        for(int j = 0; j < a.size(); j++){
            if(i - j >= b.size() || i - j < 0) continue;
            c[i] += a[j] * b[i - j];
        }
    }
    return c;
}

vector<double> Exp(vector<double>& a, int exp){
    if(exp == 0) return {1};
    if(exp == 1) return a;

    vector<double> c = Exp(a, exp / 2);
    c = Prod(c, c);

    if(exp % 2 == 1) return Prod(c, a);
    else return c;
}

int main() {
    ios::sync_with_stdio(0), cout.tie(0);

    int n, a, b; cin >> n >> a >> b;

    double x = (double)1/6;
    vector<double> r = {0, x, x, x, x, x, x}, s = {0, x, x, x, x, x, x};
    r = Exp(r, n);

    double parcial = 0;
    for(int i = a; i <= b; i++) {
        parcial += r[i];
    }

    cout << fixed << setprecision(6);
    cout << parcial << '\n';

    return 0;
}
