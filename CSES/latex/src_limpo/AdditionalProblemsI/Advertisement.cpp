const int maxn = 200010;

vector< pair< int, int > > v;

long long int l[maxn], r[maxn], h[maxn];

int main(){

    int n; scanf("%d", &n);

    v.push_back({ 0, 0 });

    for( int i = 0; i < maxn; i++){

        r[i] = n + 1;

        l[i] = 0;
    }

    for( int i = 1; i <= n; i++){

        int x; scanf("%d", &x);

        h[i] = x;

        pair< int, int > p = { x, i };

        while( v.back().first >= p.first ){

            r[v.back().second] = p.second;

            v.pop_back();

        }

        l[i] = v.back().second;

        v.push_back(p);
    }

    r[n] = n + 1;

    long long int resp = 0;

    for( int i = 1; i <= n; i++) resp = max( resp, (r[i] - l[i] - 1)*h[i]);

    printf("%lld", resp);
}
