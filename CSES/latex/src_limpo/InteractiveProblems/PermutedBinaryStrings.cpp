using i128 = __int128;
using ll = long long;

// 00001111
// 00110011
// 01010101
// dependendo da seq do dígito, descobrimos quem é quem
// se b_{a_i} teve 011 -> a_i = 011 + 1 = 4

void solve(){
	int n; cin >> n;
	vector<string> b(10, string(n, '0'));
	for(int i = 0; i < n; i++)
	{
		for(int j = 9; j >= 0; j--)
		{
			if(1 << j & i)
				b[9 - j][i] = '1';
			else
				b[9 - j][i] = '0';
		}
	}

	vector<string> a(10);

	for(int i = 0; i < 10; i++)
	{
		cout << "? ";
		cout << b[i] << endl;
		cin >> a[i];
	}

	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		int ans = 0;
		for(int j = 0; j < 10; j++)
		{
			if(a[j][i] == '1')
				ans += (1 << (9 - j));
		}
		cout << ans + 1 << " ";
	}
	cout << endl;
}
