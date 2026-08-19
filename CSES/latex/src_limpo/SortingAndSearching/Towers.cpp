const int M = 1e9 + 7;

int main () { _
	int n; cin >> n;
    multiset<int> s;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(s.upper_bound(x) == s.end()) s.insert(x);
        else{
            s.erase(s.upper_bound(x));
            s.insert(x);
        }
    }
    cout << s.size() << '\n';

	return 0;
}
