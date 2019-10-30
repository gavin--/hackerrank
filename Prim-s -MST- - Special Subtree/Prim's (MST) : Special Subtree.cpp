#include <forward_list>
#include <set>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int weight[n + 1];
    fill(weight, weight + n + 1, INT_MAX);
    set<int> mst = {1};
    set<pair<int, int>> set;
    forward_list<pair<int, int>> graph[n + 1];
    for (int x, y, r; cin >> x >> y >> r; ) {
        graph[x].emplace_front(y, r);
        graph[y].emplace_front(x, r);
    }
    int result = 0;
    auto update = [&](forward_list<pair<int, int>>& nodes) {
        for (auto& d : nodes) {
            if (mst.find(d.first) != mst.end()) {
                continue;
            }
            if (weight[d.first] > d.second) {
                set.erase({weight[d.first], d.first});
                weight[d.first] = d.second;
                set.emplace(d.second, d.first);
            }
        }
    };
    update(graph[1]);
    do {
        auto current = set.begin()->second;
        auto cost = set.begin()->first;
        set.erase(set.begin());
        mst.emplace(current);
        result += cost;
        update(graph[current]);
    } while (!set.empty());
    cout << result;
    return 0;
}
