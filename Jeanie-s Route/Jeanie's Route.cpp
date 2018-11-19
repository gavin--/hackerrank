#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> longest(int start, int parent, set<pair<int, int>>* graph) {
    vector<int> height {0, 0};
    auto diameter = 0;
    for(auto i : graph[start]) {
        if(i.first != parent) {
            auto next = longest(i.first, start, graph);
            height.emplace_back(i.second + next.first);
            diameter = max(diameter, next.second);
        }
    }
    partial_sort(height.begin(), height.begin() + 2, height.end(), greater<int>());
    return {height[0], max(height[0] + height[1], diameter)};
}

int main() {
    int n, k, result = 0, start;
    cin >> n >> k;
    vector<bool> letters(n, 0);
    for(int j; k > 0; k--) {
        cin >> j;
        letters[j - 1] = true;
        start = j - 1;
    }
    set<pair<int, int>> graph[n];
    for(int u, v, d; cin >> u >> v >> d; result += d) {
        u--;
        v--;
        graph[u].emplace(v, d);
        graph[v].emplace(u, d);
    }
    queue<int> queue;
    for(auto i = 0; i < n; i++) {
        if(graph[i].size() == 1 && letters[i] == false) {
            queue.emplace(i);
        }
    }
    while(!queue.empty()) {
        for(auto& j : graph[queue.front()]) {
            result -= j.second;
            graph[j.first].erase({queue.front(), j.second});
            if(graph[j.first].size() == 1 && letters[j.first] == false) {
                queue.emplace(j.first);
            }
        }
        queue.pop();
    }
    cout << 2 * result - longest(start, -1, graph).second;
    return 0;
}
