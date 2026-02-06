#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000 
#define pb push_back
#define F first
#define S second

#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int inv2 = 5e8 + 4;
const int maxn = 400005;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << '\n';
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even.pb(a[i]);
        else odd.pb(a[i]);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    vector<int> target;
    for (int i = 0; i < (int)even.size(); i++) {
        target.pb(even[i]);
        if (i < (int)odd.size()) target.pb(odd[i]);
    }

    vector<Node*> ptrs(n);
    Node* head = new Node(a[0]);
    ptrs[0] = head;
    Node* prev = head;
    for (int i = 1; i < n; i++) {
        Node* curr = new Node(a[i]);
        ptrs[i] = curr;
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }

    unordered_map<int, Node*> addr;
    Node* tmp = head;
    while (tmp) {
        addr[tmp->val] = tmp;
        tmp = tmp->next;
    }

    // for(auto x : target) cout << x << ' '; cout << '\n'; cout << '\n';

    int k = 0;
    int total = n;
    while (total > 4 && k < (int)target.size()) {
        total--;
        int x = target[k++];
        Node* u = addr[x];
        // cout << x << '\n';
        // printList(head);
        
        if (!u->next) {
            // cout << "ENTROU\n";
            // Se for o último, faz operação com anterior
            Node* c = u->prev;
            Node* b = c->prev;
            Node* a = b->prev;
            
            // Swap valores
            swap(a->val, c->val);
            addr[a->val] = a;
            addr[c->val] = c;

            swap(b->val, u->val);
            addr[b->val] = b;
            addr[u->val] = u;
            u = b;
        }
        // printList(head);
        
        // Rotaciona u para o head
        if (u != head)
        {
            Node* p = u -> next;
            u -> prev -> next = p -> next;
            if(p -> next)
                p -> next -> prev = u -> prev;
    
            p->next = head;
            u->prev = nullptr;
            head->prev = p;
            head = u;
        }
        // printList(head);

        head = head -> next;
    }

    // printList(head);

    vector<int> result;
    Node* cur = head;
    while (cur) {
        result.pb(cur->val);
        cur = cur->next;
    }

    if(result[0] > result[2])
    {
        swap(result[0], result[2]);
        swap(result[1], result[3]);
    }

    // cout << "RES\n";
    for(int i = 0; i < target.size() - 4; i ++) cout << target[i] << ' ';
    for(auto x : result) cout << x << ' ';
    cout << '\n';
}

signed main() {
    // _
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
