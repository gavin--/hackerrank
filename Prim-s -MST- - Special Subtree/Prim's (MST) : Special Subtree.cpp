#include <forward_list>
#include <set>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void update(int* weight, set<int>& mst, forward_list<pair<int, int>>& adj, set<pair<int, int>>& set) {
    for(auto& d : adj) {
        if(mst.find(d.first) != mst.end()) {
            continue;
        }
        if(weight[d.first] > d.second) {
            set.erase({weight[d.first], d.first});
            weight[d.first] = d.second;
            set.emplace(d.second, d.first);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int weight[N];
    fill(weight, weight + N, INT_MAX);
    set<int> mst = {0};
    set<pair<int, int>> set;
    forward_list<pair<int, int>> graph[N];
    fill(graph, graph + N, forward_list<pair<int, int>>());
    for(int x, y, r; cin >> x >> y >> r; ) {
        x--;
        y--;
        graph[x].emplace_front(y, r);
        graph[y].emplace_front(x, r);
    }
    auto result = 0;
    update(weight, mst, graph[0], set);
    do {
        auto current = set.begin()->second;
        auto cost = set.begin()->first;
        set.erase(set.begin());
        mst.emplace(current);
        result += cost;
        update(weight, mst, graph[current], set);
    } while(!set.empty());
    cout << result;
    return 0;
}
