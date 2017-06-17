#include <forward_list>
#include <set>
#include <climits>
#include <iostream>
using namespace std;

int reachable(int i) {
    if(i == INT_MAX) {
        return -1;
    }
    return i;
}

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
        do {
            auto current = set.begin()->second;
            set.erase(set.begin());
            for(auto& i : graph[current]) {
                if(distance[i.first] > distance[current] + i.second) {
                    set.erase({distance[i.first], i.first});
                    distance[i.first] = distance[current] + i.second;
                    set.emplace(distance[i.first], i.first);
                }
            }
        } while(!set.empty());
        for(auto i = 0; i < S; i++) {
            cout << reachable(distance[i]) << ' ';
        }
        for(auto i = S + 1; i < N; i++) {
            cout << reachable(distance[i]) << ' ';
        }
    }
    return 0;
}
