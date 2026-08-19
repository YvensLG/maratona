const ll INF = 1e15, logINF = 50;

vector<ll> a(50);

void solve(){
    ll n; cin >> n;
	ll tot = 0;

	a[0] = 1;
	for(int i = 1; i < logINF; i++)
		a[i] = a[i - 1] * 2 + (1LL << i);

	ll aux = 0;

	for(int bit = 0; bit <= logINF; bit++) {
		if((n & (1LL << bit)) == 0) continue;

		if(bit == 0) {
			aux += (1LL << bit);
			tot = 1;
			continue;
		}

		tot += (aux + 1) + a[bit - 1];
		aux += (1LL << bit);
	}

	cout << tot << '\n';
}
