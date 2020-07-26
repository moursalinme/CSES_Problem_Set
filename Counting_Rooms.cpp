#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <vector <bool>> adj(1000, vector<bool> (1000, 0));
vector <vector <bool>> vis(1000, vector<bool> (1000, 0));
vector <pair<int, int>> can_move = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool is_valid(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m; 
}

void dfs(int i , int j) {
    vis[i][j] = 1;
    for (auto can: can_move) {
        int x = i + can.first;
        int y = j + can.second;
        if(is_valid(x, y) && adj[x][y] == 1 && vis[x][y] == 0) {
            dfs(x, y);
        } 
    }
}

void solve() {
    cin >> n >> m;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        int j = 0;
        for (auto ch : s) {
            ch == '.' ? adj[i][j] = 1 : 1;
            ++j;
        }
    }
    int cnt = 0;
            
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (adj[i][j] == true && vis[i][j] == false) {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}   

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}