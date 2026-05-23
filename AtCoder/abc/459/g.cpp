#include <bits/stdc++.h>
#define int long long

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 1000000000
#define LINF 1000000000000000000LL
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int, int> pii;

int C1, C2, V1, V2, Su0, Du0, Sv0, Dv0;

int euclid(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    int d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

int floor_div(int a, int b) {
    if (a >= 0) return a / b;
    return (a - b + 1) / b; 
}

int cost(int k, int m) {
    int Su = Su0 + k * C2;
    int Du = Du0 + m * C1;
    int Sv = Sv0 - m * C2;
    int Dv = Dv0 - k * C1;
    return max(abs(Su), abs(Du)) + max(abs(Sv), abs(Dv));
}

int ternary_m(int k) {
    int p1 = ((Du0 - Su0) % 2 + 2) % 2;
    int p2 = ((Sv0 - Dv0) % 2 + 2) % 2;

    int req_m;
    if (C1 % 2 == 1 && C2 % 2 == 1) req_m = ((k + p1) % 2 + 2) % 2;
    else if (C1 % 2 == 0) req_m = p2;
    else req_m = p1;
    
    int abs_Su = abs(Su0 + k * C2);
    int abs_Dv = abs(Dv0 - k * C1);
    
    int m1 = 0;
    int m2 = Sv0 / C2;
    int L = min(m1, m2) - 50;
    int R = max(m1, m2) + 50;
    
    while (((L % 2) + 2) % 2 != req_m) L++;
    while (((R % 2) + 2) % 2 != req_m) R--;
    
    if (L > R) return LINF;
    
    int b = L;
    auto eval = [&](int j) { return cost(k, b + 2 * j); };

    R = (R - L) / 2; L = 0;

    while (R - L >= 5) {
        int mid = (R + L) / 2;
		if (eval(mid) > eval(mid+1)) L = mid;
		else R = mid+1;
    }
    
    int ans = LINF;
    for (int i = L; i <= R; ++i) {
        ans = min(ans, eval(i));
    }
    
    return ans;
};

void solve() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    
    int g = gcd(A, B);
    if (X % g != 0 || Y % g != 0) {
        cout << -1 << "\n";
        return;
    }
    A /= g; B /= g; X /= g; Y /= g;
    
    C1 = A + B;
    C2 = B - A;
    V1 = X + Y;
    V2 = X - Y;
    
    if (C1 % 2 == 0 && C2 % 2 == 0) {
        if (V1 % 2 != 0) {
            cout << -1 << "\n";
            return;
        }
        C1 /= 2;
        C2 /= 2;
        V1 /= 2;
        V2 /= 2;
    }
    
    // C1 * x0 + C2 * y0 = 1
    int x0, y0;
    euclid(C1, C2, x0, y0);
    
    // C1 * Su0 + C2 * Dv0 = V1
    Su0 = x0 * V1;
    Dv0 = y0 * V1;
    int shift1 = floor_div(Su0, C2);
    Su0 -= shift1 * C2;
    Dv0 += shift1 * C1;
    
    // C1 * Du0 + C2 * Sv0 = V2
    Du0 = y0 * V2;
    Sv0 = x0 * V2;
    int shift2 = floor_div(Du0, C1);
    Du0 -= shift2 * C1;
    Sv0 += shift2 * C2;
    
    // busca ternaria
    int req_k = -1;
        if (C1 % 2 == 0) req_k = ((Du0 - Su0) % 2 + 2) % 2;
        if (C2 % 2 == 0) req_k = ((Sv0 - Dv0) % 2 + 2) % 2;

    auto ternary_k = [&](int p_k) {
        int k1 = 0;
        int k2 = Dv0 / C1;
        int L_k = min(k1, k2) - 50;
        int R_k = max(k1, k2) + 50;
        
        while (((L_k % 2) + 2) % 2 != p_k) L_k++;
        while (((R_k % 2) + 2) % 2 != p_k) R_k--;

        if (L_k > R_k) return LINF;
        
        int L = 0, R = (R_k - L_k) / 2;
        
        auto eval = [&](int s) {
            int k = L_k + 2 * s;
            return ternary_m(k);
        };

        while (R - L >= 5) {
            int mid = (R + L) / 2;
            if (eval(mid) > eval(mid+1)) L = mid;
            else R = mid+1;
        }
        
        int ans = LINF;
        for (int i = L; i <= R; ++i) {
            ans = min(ans, eval(i));
        }

        return ans;
    };
        
    if (req_k != -1) {
        cout << ternary_k(req_k) << "\n";
    } else {
        cout << min(ternary_k(0), ternary_k(1)) << "\n";
    }
}

signed main() { _
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}