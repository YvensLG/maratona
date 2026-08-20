using vi = vector<int>;

void solve(){
    string s; cin >> s;
    int n = s.size();

    set<int> pos[2];
    multiset<int> len;

    pos[0].insert(-1); pos[1].insert(-1);

    for( int i = 0; i < n; i++ ){
        len.insert(i - *pos[s[i] - '0'].rbegin());
        pos[s[i] - '0'].insert(i);
    }

    len.insert(n - *pos[0].rbegin());
    pos[0].insert(n);
    len.insert(n - *pos[1].rbegin());
    pos[1].insert(n);

    int q; cin >> q;
    while( q-- ){
        int p; cin >> p; p--;
        int x = s[p] - '0';

        // Remover do set

        auto it1 = pos[x].erase(pos[x].find(p));
        len.erase(len.find(*it1 - p));
        len.erase(len.find(p - *prev(it1)));
        len.insert(*it1 - *prev(it1));

        // Inserir no outro

        x = 1 - x;
        s[p] = '0' + x;
        auto it2 = pos[x].insert(p).first;
        len.erase(len.find(*next(it2) - *prev(it2)));
        len.insert(*next(it2) - *it2);
        len.insert(*it2 - *prev(it2));

        cout << *len.rbegin() - 1 << " ";
    }
    cout << endl;
}
