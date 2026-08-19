int main() {
	ll n, k, cont = 1, soma = 0;
	cin >> n >> k;
	ll a[k];
	for(int i=0; i<k; i++){
		cin >> a[i];
		cont *= 2;
	}
	for(cont--; cont > 0; cont--){
		ll aux = cont;
		ll bit, total = 0;
		ll num = n;
		for(int j=0; j<k; j++){
			bit = aux % 2;
			if(bit == 1){
				total += bit;
				num = num / a[j];
			}
			aux = aux >> 1;
		}
		if(total % 2 == 1) soma += num;
		else soma -= num;
	}
	cout << soma << '\n';
}
