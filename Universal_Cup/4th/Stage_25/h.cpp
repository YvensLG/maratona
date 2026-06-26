#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t ull;
struct H{
    ull x; H(ull x = 0) : x(x) {}
    H operator + (H o) {return x + o.x + (x + o.x < x); }
    H operator - (H o) { return *this + ~o.x; }
    H operator * (H o){
        auto m = (__uint128_t)x *o.x; 
        return H((ull)m) + (ull)(m>>64);
    }
    ull get() const { return x + !~x;}
    bool operator == (H o) const { return get() == o.get(); }
    bool operator < (H o) const { return get() < o.get(); }
};

static const H C = (ll)1e11 + 3;

struct HashInterval{
    vector<H> ha, pw; 
    HashInterval( string& str ) : ha(sz(str) + 1), pw(ha){
        pw[0] = 1; 
        rep(i, 0, sz(str))
            ha[i + 1] = ha[i] * C + str[i], 
            pw[i + 1] = pw[i] * C; 
    }
    H hashInterval( int a, int b ){
        return ha[b] - ha[a]*pw[b - a]; 
    }
};

vector<H> getHashes( string &str, int length ){
    if(sz(str) < length ) return {};
    H h = 0, pw = 1; 
    rep( i, 0, length )
        h = h  * C + str[i], pw = pw * C; 
    vector<H> ret = {h}; 
    rep(i, length, sz(str)){
        ret.push_back(h = h*C + str[i] - pw *str[i - length]); 
    }
    return ret;
}

H hashString( string &s ){ H h{}; for( char c : s ) h = h*C + c; return h; }

void solve() {
    string s; cin >> s;
    
    vector<int> next(sz(s), -1);

    for( int i = sz(s) - 2; i >= 0; i-- ){
        next[i] = next[i + 1];
        if(s[i] != s[i + 1]) next[i] = i; 
    }

    HashInterval h(s); 

    auto cmp = [&]( int i, int j ){
        int len = abs(i - j); 

        bool invert = false; 
        if( i > j ){ swap( i, j ); invert = true; }

        int id = next[i]; 
        if( id == -1 || id >= j ) return 1; // iguais

        return ((s[id + 1] < s[id])^invert); 
    };

    vector<int> p(s.size()); 
    iota( p.begin(), p.end(), 0 ); 
    stable_sort( p.begin(), p.end(), cmp ); 

    int m = (sz(s) - 1)/2; 
    cout << s.substr(0,p[m]) + s.substr(p[m] + 1,s.size()) << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while( t-- )
    solve();

    return 0;
}
