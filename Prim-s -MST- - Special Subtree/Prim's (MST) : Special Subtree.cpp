#include <forward_list>
#include <set>
#include <iostream>
#include <climits>
using namespace std;
 
void update(int* weight, set<int>& mst, forward_list<pair<int, int>>& adj, set<pair<int, int>>& s) {
	for(auto& d : adj) {
		if(mst.find(d.first) != mst.end()) {
			continue;
		}
		if(weight[d.first] > d.second) {
            s.erase({weight[d.first], d.first});
			weight[d.first] = d.second;
			s.emplace(d.second, d.first);
		}
	}
}
 
int main() {
	int N, M;
	cin >> N >> M;
    int weight[N];
    for(auto i = 0; i != N; i++) {
        weight[i] = INT_MAX;
    }
	set<pair<int, int>> s;
	forward_list<pair<int, int>> graph[N];
	for(auto i = 0; i != M; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		x--;
		y--;
		graph[x].emplace_front(y, r);
		graph[y].emplace_front(x, r);
	}
	set<int> mst = {0};
	auto result = 0;
	update(weight, mst, graph[0], s);
	while(!s.empty()) {
		auto current = s.begin()->second;
		auto cost = s.begin()->first;
		s.erase(s.begin());
		mst.emplace(current);
		result += cost;
		update(weight, mst, graph[current], s);
	}
	cout << result;
	return 0;
}
