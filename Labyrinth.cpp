#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> src, dst;
vector <vector <bool>> adj(1000, vector<bool> (1000, 0));
vector <vector <bool>> vis(1000, vector<bool> (1000, 0));
vector <pair<int, int>> can_move = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool is_valid(int a, int b) {
    return a >= 0 && a < n && b >= 0 && b < m; 
}

void bfs() {
    queue <pair<int, int>> q;
    q.push(src);
    char pathc[1000][1000] ;
    vector<vector<pair<int, int>>> par(1000, vector<pair<int, int>> (1000, {-1, -1}));
    vis[src.first][src.second] = 1;

    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if(vis[dst.first][dst.second] == 1) break;

        for (int i = 0; i < 4; ++i) {
            int x = can_move[i].first + top.first;
            int y = can_move[i].second + top.second;
        
            if (is_valid(x, y) && vis[x][y] == false && adj[x][y] == 1) {
                q.push({x,y});
                vis[x][y] = 1;
                if (i == 0) pathc[x][y] = 'L';
                if (i == 1) pathc[x][y] = 'R';
                if (i == 2) pathc[x][y] = 'D';
                if (i == 3) pathc[x][y] = 'U';
                par[x][y] = {top.first, top.second};
            }   
        }
    }

    if (vis[dst.first][dst.second]) {
        cout << "YES" << endl;
        int x = dst.first, y = dst.second;
        vector <char> answer;
        while(par[x][y].first != -1) {
            answer.push_back(pathc[x][y]);
            int e = x, f = y;
            x = par[e][f].first;
            y = par[e][f].second;
        }
        cout << answer.size() << endl;
        for (int i = answer.size()-1; i >=0; --i) 
            cout << answer[i];
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

void solve() {
    cin >> n >> m;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        int j = 0;
        for (auto ch : s) {
            ch == '.' || ch == 'A' || ch == 'B'? adj[i][j] = 1 : 1;
            if (ch == 'A') src = {i, j};
            if (ch == 'B') dst = {i, j};
            ++j;
        }
    }
    bfs();
}   

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}