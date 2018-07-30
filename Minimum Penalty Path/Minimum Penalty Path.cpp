#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int SIZE = 1024;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    for(int x, y, c; m > 0; m--) {
        cin >> x >> y >> c;
        graph[x].emplace_back(y, c);
        graph[y].emplace_back(x, c);
    }
    cin >> a >> b;
    vector<bool> visited[n + 1];
    for(int i = 0; i <= n; i++) {
        visited[i].resize(SIZE);
    }
    visited[a][0] = true;
    queue<pair<int, int>> queue;
    queue.emplace(a, 0);
    do {
        for(auto& next : graph[queue.front().first]) {
            if(!visited[next.first][queue.front().second | next.second]) {
                visited[next.first][queue.front().second | next.second] = true;
                queue.emplace(next.first, queue.front().second | next.second);
            }
        }
        queue.pop();
    } while(!queue.empty());
    for(int i = 0; i < SIZE; i++) {
        if(visited[b][i]) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
