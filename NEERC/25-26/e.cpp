#include<bits/stdc++.h>

using namespace std;

const int N = 2010;
vector <pair <int, int>> d = {{-1, -1},{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int mark[N][N];

int query(int x, int y){
    cout << "? " << x << ' ' << y << '\n';
    cout << flush;
    char t;
    cin >> t;
    if(t == '0'){
        assert(false);
    }
    return (t == 'B' ? 0 : 1);
}

bool viz(int a, int b, int c, int dd){
    for(auto [dx, dy] : d){
        if(a+dx == c and b+dy == dd)
            return true;
    }
    return false;
}

int n;

void solve(){
    vector <pair <int, int>> comp[2];
    int t = query(1000, 1000);
    comp[t].push_back({1000, 1000});
    vector <pair <int, int>> alt;
    alt.push_back({1000, 1000});
    mark[1000][1000] = t; 
    while(comp[0].size() < n and comp[1].size() < n){
        bool aux = true;
        for(auto [a, b] : comp[0]){
            for(auto [dx, dy] : d){
                if(mark[a+dx][b+dy] == 1){
                    for(auto [ddx, ddy] : d){
                        if(mark[a+ddx][b+ddy] == -1 and viz(a+dx, b+dy, a+ddx, b+ddy)){
                            aux = false;
                            mark[a+ddx][b+ddy] = query(a+ddx, b+ddy);
                            alt.push_back({a+ddx, b+ddy});
                            comp[mark[a+ddx][b+ddy]].push_back({a+ddx, b+ddy});
                            break;
                        }
                    }
                }
                if(!aux)
                    break;
            }
            if(!aux)
                break;
        }
        if(aux){
            for(auto [a, b] : comp[0]){
                for(auto [dx, dy] : d){
                    if(mark[a+dx][b+dy] == -1){
                        aux = false;
                        mark[a+dx][b+dy] = query(a+dx, b+dy);
                        alt.push_back({a+dx,b+dy});
                        comp[1].clear();
                        comp[mark[a+dx][b+dy]].push_back({a+dx, b+dy});
                        break;
                    }
                }
                if(!aux)
                    break;
            }
        }
        if(aux){
            for(auto [a, b] : comp[1]){
                for(auto [dx, dy] : d){
                    if(mark[a+dx][b+dy] == -1){
                        aux = false;
                        mark[a+dx][b+dy] = query(a+dx, b+dy);
                        alt.push_back({a+dx,b+dy});
                        comp[0].clear();
                        comp[mark[a+dx][b+dy]].push_back({a+dx, b+dy});
                        break;
                    }
                }
                if(!aux)
                    break;
            }
        }
    }
    if(comp[0].size() == n){
        cout << "! B ";
        for(int i = 0;i < comp[0].size();i++){
            cout << comp[0][i].first << ' ' << comp[0][i].second << ' ';
        }
        cout << '\n';
        cout << flush;
    }
    else{
        cout << "! W ";
        for(int i = 0;i < comp[1].size();i++){
            cout << comp[1][i].first << ' ' << comp[1][i].second << ' ';
        }
        cout << '\n';
        cout << flush;
    }
    for (auto p: alt) {
        mark[p.first][p.second] = -1;
    }
}


int main(){
    memset(mark, -1, sizeof mark);
    int t;
    cin >> t;
    cin >> n;
    while(t--){
        solve();
    }
}