using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int maxn = 3e3;
const int alphabet = 26;

int ptr[alphabet], p[alphabet][maxn];
bitset<maxn*maxn> marc[alphabet];
bool ok[alphabet];

void solve(){
    int n, q; cin >> n >> q;

    FOR(i, 0, n){
        fill(ptr, ptr + q, 0);
        FOR(j, 0, n){
            char c; cin >> c;
            p[c - 'A'][ptr[c - 'A']++] = j;
        }

        FOR(c, 0, q) if( !ok[c] ){
            FOR(j, 0, ptr[c] ){
                FOR(k, j + 1, ptr[c])
                    if( marc[c][p[c][j]*n + p[c][k]] ){ ok[c] = true; break; }
                    else marc[c][p[c][j]*n + p[c][k]] = true;
                if( ok[c] ) break;
            }
        }
    }
    FOR(c, 0, q) cout << ((ok[c]) ? "YES" : "NO" ) << '\n';
}
