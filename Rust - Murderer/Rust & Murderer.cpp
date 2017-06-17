#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, M, S; cin >> N >> M; cout << endl) {
        set<int> graph[N];
        fill(graph, graph + N, set<int>());
        for(int x, y; M > 0; M--) {
            cin >> x >> y;
            x--;
            y--;
            graph[x].emplace(y);
            graph[y].emplace(x);
        }
        cin >> S;
        S--;
        queue<int> queue;
        queue.emplace(S);
        list<int> unvisited;
        for(auto i = 0; i < S; i++) {
            unvisited.emplace_back(i);
        }
        for(auto i = S + 1; i < N; i++) {
            unvisited.emplace_back(i);
        }
        int distance[N];
        fill(distance, distance + N, 0);
        do {
            auto front = queue.front();
            queue.pop();
            for(auto it = unvisited.begin(); it != unvisited.end(); ) {
                if(graph[front].find(*it) == graph[front].end()) {
                    queue.emplace(*it);
                    distance[*it] = distance[front] + 1;
                    it = unvisited.erase(it);
                } else {
                    it++;
                }
            }
        } while(!queue.empty());
        for(auto i = 0; i < S; i++) {
            cout << distance[i] << ' ';
        }
        for(auto i = S + 1; i < N; i++) {
            cout << distance[i] << ' ';
        }
    }
    return 0;
}
