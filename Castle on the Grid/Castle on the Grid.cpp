#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<vector<pair<int, int>>>> make_graph(int N) {
    vector<bool> grid[N];
    for(auto i = 0; i < N; i++) {
        grid[i] = vector<bool>();
        for(auto j = 0; j < N; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                grid[i].emplace_back(true);
            } else {
                grid[i].emplace_back(false);
            }
        }
    }
    vector<vector<vector<pair<int, int>>>> graph(N, vector<vector<pair<int, int>>>(N));
    for(auto i = 0; i < N; i++) {
        for(auto j = 0; j < N; j++) {
            graph[i][j] = vector<pair<int, int>>();
            for(auto k = i + 1; k < N && grid[k][j]; k++) {
                graph[i][j].emplace_back(k, j);
            }
            for(auto k = i - 1; k >= 0 && grid[k][j]; k--) {
                graph[i][j].emplace_back(k, j);
            }
            for(auto k = j + 1; k < N && grid[i][k]; k++) {
                graph[i][j].emplace_back(i, k);
            }
            for(auto k = j - 1; k >= 0 && grid[i][k]; k--) {
                graph[i][j].emplace_back(i, k);
            }
        }
    }
    return graph;
}

int main() {
    int N, a, b, c, d;
    cin >> N;
    auto graph = make_graph(N);
    cin >> a >> b >> c >> d;
    vector<bool> visited[N];
    fill(visited, visited + N, vector<bool>(N, false));
    queue<pair<int, int>> queue;
    queue.emplace(a, b);
    visited[a][b] = true;
    for(auto result = 0; !queue.empty(); result++) {
        for(auto size = queue.size(); size > 0; size--) {
            auto front = queue.front();
            if(front.first == c && front.second == d) {
                cout << result;
                return 0;
            }
            queue.pop();
            for(auto& i : graph[front.first][front.second]) {
                if(!visited[i.first][i.second]) {
                    queue.emplace(i.first, i.second);
                    visited[i.first][i.second] = true;
                }
            }
        }
    }
    return 0;
}
