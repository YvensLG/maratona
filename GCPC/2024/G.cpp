#include <bits/stdc++.h>
using namespace std;

#define sz(v) int((v).size())
#define die return cout << "no\n", 0

using Piece = vector<string>;

Piece p2x15 = {
    "LLLLYYYYNNNYPPP",
    "LIIIIIYNNYYYYPP"
};

Piece p2x10 = {
    "LLLLNNNPPP",
    "LIIIIINNPP"
};

Piece p4x5 = {
    "LNVVV",
    "LNZZV",
    "LNNZV",
    "LLNZZ"
};

Piece p5x5 = {
    "LNVVV",
    "LNZZV",
    "LNNZV",
    "LLNZZ",
    "IIIII"
};

Piece p3x5_1 = {
    "UUXUU",
    "UXXXU",
    "UUXUU"
};

Piece p3x5_2 = {
    "PTTTP",
    "PPTPP",
    "PPTPP"
};

void place(vector<string>& grid, int i, int j, Piece const& p, bool fh, bool fw) {
    for (int ii = 0; ii < sz(p); ii++) {
        for (int jj = 0; jj < sz(p[ii]); jj++) {
            int a = fh ? sz(p) - ii - 1 : ii;
            int b = fw ? sz(p[ii]) - jj - 1 : jj;

            grid[i + ii][j + jj] = p[a][b];
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int h, w; cin >> h >> w;

    bool flip = false;

    if (w%5 != 0) flip = true, swap(h, w);
    if (w%5 != 0) die;

    vector<string> grid(h, string(w, '.'));

    if (h == 1) {
        if (w != 5) die;

        for (int i = 0; i < 5; i++) grid[0][i] = 'I';
    } else if(h == 2) {
        if (w == 5) die;

        int st = 0;
        if (w%2) {
            place(grid, 0, 0, p2x15, 0, 0);
            st += 15;
        }
        for (; st < w; st += 10) place(grid, 0, st, p2x10, 0, 0);
    } else {
        int row = 0;

        if (h % 3 == 1) {
            for (int i = 0, f = 0; i < w; i += 5, f ^= 1) {
                place(grid, 0, i, p4x5, f, 0);
            }
            row += 4;
        } else if(h % 3 == 2) {
            for (int i = 0, f = 0; i < w; i += 5, f ^= 1) {
                place(grid, 0, i, p5x5, f, 0);
            }
            row += 5;
        }

        for (int i = row, f1 = 0; i < h; i += 3, f1 ^= 1) {
            for (int j = 0, f2 = 0; j < w; j += 5, f2 ^= 1) {
                int f = f1  ^ f2;

                if (f) place(grid, i, j, p3x5_1, 0, 0);
                else place(grid, i, j, p3x5_2, 0, 0);
            }
        }
    }

    cout << "yes\n";

    if (flip) {
        for (int j = 0; j < w; j++) {
            for (int i = 0; i < h; i++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}