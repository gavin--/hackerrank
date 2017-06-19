#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> longest(int start, int parent, vector<bool>& letters, vector<set<pair<int, int>>>& graph) {
    vector<int> height {0, 0};
    auto diameter = 0;
    for(auto i : graph[start]) {
        if(i.first != parent) {
            auto next = longest(i.first, start, letters, graph);
            height.emplace_back(i.second + next.first);
            diameter = max(diameter, next.second);
        }
    }
    partial_sort(height.begin(), height.begin() + 2, height.end(), greater<int>());
    return {height[0], max(height[0] + height[1], diameter)};
}

int main() {
    int N, K, result = 0, start;
    cin >> N >> K;
    vector<bool> letters(N, 0);
    for(int j; K > 0; K--) {
        cin >> j;
        j--;
        letters[j] = true;
        start = j;
    }
    vector<set<pair<int, int>>> graph(N, set<pair<int, int>>());
    for(int u, v, d; cin >> u >> v >> d; result += d) {
        u--;
        v--;
        graph[u].emplace(v, d);
        graph[v].emplace(u, d);
    }
    queue<int> queue;
    for(auto i = 0; i < N; i++) {
        if(graph[i].size() == 1 && letters[i] == false) {
            queue.emplace(i);
        }
    }
    while(!queue.empty()) {
        auto front = queue.front();
        queue.pop();
        for(auto& j : graph[front]) {
            result -= j.second;
            graph[j.first].erase({front, j.second});
            if(graph[j.first].size() == 1 && letters[j.first] == false) {
                queue.emplace(j.first);
            }
        }
    }
    cout << 2 * result - longest(start, -1, letters, graph).second;
    return 0;
}
