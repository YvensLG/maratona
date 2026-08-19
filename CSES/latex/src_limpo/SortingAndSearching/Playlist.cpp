const int M = 1e9 + 7;

int main () { _
	int n; cin >> n;
    vector<int> k(n);

    int cnt = 0;
    map<int, int> mp;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(mp.find(x) == mp.end()){
            cnt++;
            mp[x] = cnt;
        }
        k[i] = mp[x];
    }

    vector<int> f(cnt+1);
    for(int i=0; i<=cnt; i++){
        f[i] = -1;
    }

    int ini = 0, fim = 0;
    int M = 0;

    while(ini <= n-1 && fim <= n-1){
        if(ini <= f[k[fim]] && f[k[fim]] <= fim){
            ini = f[k[fim]] + 1;
        }
        f[k[fim]] = fim;
        M = max(M, fim - ini + 1);
        fim++;
    }

    cout << M << '\n';

	return 0;
}
