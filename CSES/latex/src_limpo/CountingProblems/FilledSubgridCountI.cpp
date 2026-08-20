using ll = long long;

const int maxn = 3e3 + 10;
const int alphabet = 26;

char mat[maxn][maxn];
int square[maxn][maxn]; // maior quadrado com canto inf-dir em ( i, j );
ll resp[alphabet];

int main(){
  int n, k; cin >> n >> k;

  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < n; j++ ){
      cin >> mat[i][j];

      if( !i || !j ) square[i][j] = 1;
      else if( mat[i][j] != mat[i - 1][j] || mat[i][j] != mat[i][j - 1] ) square[i][j] = 1;
      else{
        int x = min( square[i - 1][j], square[i][j - 1] );
        if( mat[i][j] != mat[i - x][j - x] ) square[i][j] = x;
        else square[i][j] = x + 1;
      }

      resp[mat[i][j] - 'A'] += square[i][j];
    }
  }

  for( int i = 0; i < k; i++ ) cout << resp[i] << endl;
}
