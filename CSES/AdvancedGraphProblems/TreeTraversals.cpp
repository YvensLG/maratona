#include <bits/stdc++.h>
#define pb push_back
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pc __builtin_popcount
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
struct node {
    int id = -1;
    node *left, *right;
};

vector<int> preord, inord, inord_rev;
int n;
int preord_pos = 0;

node* process(int left, int right) {
    if(left > right) return nullptr;
    int at = preord[preord_pos++];
    int pos = inord_rev[at];

    node* novo = new node();
    novo->id = at;
    novo->left = process(left, pos - 1);
    novo->right = process(pos + 1, right);
    
    return novo;
}

void answer(node* tree) {
    if(tree == nullptr) return;
    answer(tree->left);
    answer(tree->right);
    cout << tree->id << ' ';
}

void solve(){
    cin >> n;
    preord.resize(n); inord.resize(n); inord_rev.resize(n + 1);

    for(int i = 0; i < n; i++) cin >> preord[i];
    for(int i = 0; i < n; i++) {
        cin >> inord[i];
        inord_rev[inord[i]] = i;
    }

    int root = preord[0];
    node* tree = process(0, n-1);

    answer(tree);
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; for(int i = 1; i <= t; i++)
    solve();
    return 0;
}