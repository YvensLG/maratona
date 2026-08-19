#include <bits/stdc++.h>
using namespace std;
 
const int inf = 2e9;
vector<int> lef, rig, a;
const int MAX = 2e5 + 5;

struct seg {
	int n, t[4*MAX];

	int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;

        int left = query(v*2, tl, tm, l, min(r, tm));
        int right = query(v*2+1, tm+1, tr, max(l, tm+1), r);

        return max(left, right);
    }   

	void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }
};
 
void calc() {
    int n = a.size();
    lef.resize(n), rig.resize(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        lef[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        rig[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

void solve() {
    int n; cin >> n; n += 2;
    a.resize(n); a[0] = inf;
    for(int i = 1; i <= n - 2; i++) cin >> a[i];
    a[n - 1] = inf;

    calc();
    
    vector<pair<int, int>> seq(n);
    for(int i = 0; i < n; i++) seq[i] = {a[i], i};
    sort(seq.begin(), seq.end());

    seg tree; tree.n = n;

    for(int i = 0; i < n - 2; i++) {
        int idx = seq[i].second;
        int L = lef[idx], R = rig[idx];

        int ans_left = tree.query(1, 0, n - 1, L + 1, idx);
        int ans_right = tree.query(1, 0, n - 1, idx, R - 1);

        tree.update(1, 0, n - 1, idx, max(ans_left, ans_right) + 1);
    }

    cout << tree.query(1, 0, n - 1, 0, n - 1) << "\n";

}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
