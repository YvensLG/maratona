using i128 = __int128;
using ll = long long;

// podemos tratar x e y separadamente
// x1 x2 x3 x4 ... xk
// k -> (xk - xk-1) + (xk - xk-2) + ... + (xk - x1) = k * xk - pref(k)

void print_i128(i128 x) {
    if (x == 0) { cout << '0'; return; }
    if (x < 0) { cout << '-'; x = -x; }
    string s;
    while (x > 0) {
		s.push_back('0' + int(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(){
	int n; cin >> n;
	vector<int> px(n + 1), py(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> px[i] >> py[i];
	}
	sort(px.begin() + 1, px.end());
	sort(py.begin() + 1, py.end());

	vector<i128> prefx(n + 1), prefy(n + 1);
	for(int i = 1; i <= n; i++){
		prefx[i] = prefx[i - 1] + px[i];
		prefy[i] = prefy[i - 1] + py[i];
	}

	i128 ans = 0;

	for(int i = 1; i <= n; i++){
		ans += (ll)i * px[i] - prefx[i];
		ans += (ll)i * py[i] - prefy[i];
	}

	print_i128(ans);
	cout << '\n';
}
