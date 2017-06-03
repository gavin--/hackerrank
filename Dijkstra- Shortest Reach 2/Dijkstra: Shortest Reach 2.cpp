#include <forward_list>
#include <set>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, M, S; cin >> N >> M; cout << endl) {
        forward_list<pair<int, int>> graph[N];
        int distance[N];
        fill(distance, distance + N, INT_MAX);
        for(auto i = 0; i != M; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            graph[x - 1].emplace_front(y - 1, r);
            graph[y - 1].emplace_front(x - 1, r);
        }
        cin >> S;
        S--;
        distance[S] = 0;
        set<pair<int, int>> set;
        set.emplace(0, S);
        while(!set.empty()) {
            auto current = set.begin()->second;
            set.erase(set.begin());
            for(auto& i : graph[current]) {
                if(distance[i.first] > distance[current] + i.second) {
                    set.erase({distance[i.first], i.first});
                    distance[i.first] = distance[current] + i.second;
                    set.emplace(distance[i.first], i.first);
                }
            }
        }
        for(auto& i : distance) {
            if(i != 0) {
                if(i == INT_MAX) {
                    cout << -1;
                } else {
                    cout << i;
                }
                cout << ' ';
            }
        }
    }
    return 0;
}
