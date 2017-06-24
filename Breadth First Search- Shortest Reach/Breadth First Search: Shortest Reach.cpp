#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int n, m; cin >> n >> m; cout << endl) {
        vector<int> graph[n], visited(n);
        for(auto i = 0; i != m; i++) {
            int j, k;
            cin >> j >> k;
            graph[j - 1].emplace_back(k - 1);
            graph[k - 1].emplace_back(j - 1);
        }
        int s, distance[n];
        fill(distance, distance + n, -1);
        cin >> s;
        queue<int> queue;
        queue.emplace(s - 1);
        visited[s - 1] = true;
        for(auto d = 6; !queue.empty(); d += 6) {
            for(auto size = queue.size(); size > 0; size--) {
                auto front = queue.front();
                queue.pop();
                for(auto i : graph[front]) {
                    if(visited[i] == false) {
                        distance[i] = d;
                        queue.emplace(i);
                        visited[i] = true;
                    }
                }
            }
        }
        for(auto i = 0; i < s - 1; i++) {
            cout << distance[i] << ' ';
        }
        for(auto i = s; i < n; i++) {
            cout << distance[i] << ' ';
        }
    }
    return 0;
}
