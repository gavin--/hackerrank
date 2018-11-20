#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<vector<pair<int, int>>>> make_graph(int n) {
    vector<bool> grid[n];
    for(int i = 0; i < n; i++) {
        for(auto j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i].emplace_back(c == '.');
        }
    }
    vector<vector<vector<pair<int, int>>>> graph(n, vector<vector<pair<int, int>>>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = vector<pair<int, int>>();
            for(int k = i + 1; k < n && grid[k][j]; k++) {
                graph[i][j].emplace_back(k, j);
            }
            for(int k = i - 1; k >= 0 && grid[k][j]; k--) {
                graph[i][j].emplace_back(k, j);
            }
            for(int k = j + 1; k < n && grid[i][k]; k++) {
                graph[i][j].emplace_back(i, k);
            }
            for(int k = j - 1; k >= 0 && grid[i][k]; k--) {
                graph[i][j].emplace_back(i, k);
            }
        }
    }
    return graph;
}

int main() {
    int n, a, b, c, d;
    cin >> n;
    auto graph = make_graph(n);
    cin >> a >> b >> c >> d;
    vector<vector<bool>> visited1(n, vector<bool>(n)), visited2(n, vector<bool>(n));
    queue<pair<int, int>> queue1, queue2;
    queue1.emplace(a, b);
    queue2.emplace(c, d);
    visited1[a][b] = true;
    visited2[c][d] = true;
    for(int result = 0; !queue1.empty() && !queue2.empty(); result++) {
        for(auto size = queue1.size(); size > 0; size--) {
            if(visited2[queue1.front().first][queue1.front().second]) {
                cout << result;
                return 0;
            }
            for(auto& i : graph[queue1.front().first][queue1.front().second]) {
                if(!visited1[i.first][i.second]) {
                    queue1.emplace(i.first, i.second);
                    visited1[i.first][i.second] = true;
                }
            }
            queue1.pop();
        }
        swap(queue1, queue2);
        swap(visited1, visited2);
    }
    return 0;
}
