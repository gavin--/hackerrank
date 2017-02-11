#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int q;
    for(cin >> q; q > 0; q--) {
        int n, m;
        cin >> n >> m;
        vector<bool> graph[n], visited(n);
        fill(graph, graph + n, vector<bool>(n));
        for(auto i = 0; i != m; i++) {
            int j, k;
            cin >> j >> k;
            graph[j - 1][k - 1] = true;
            graph[k - 1][j - 1] = true;
        }
        int s, distance[n];
        fill(distance, distance + n, -1);
        cin >> s;
        queue<int> queue;
        queue.emplace(s - 1);
        visited[s - 1] = true;
        for(auto d = 6; !queue.empty(); d += 6) {
            int size = queue.size();
            while(size > 0) {
                size--;
                auto front = queue.front();
                queue.pop();
                for(auto i = 0; i != n; i++) {
                    if(visited[i] == false && graph[i][front]) {
                        distance[i] = d;
                        queue.emplace(i);
                        visited[i] = true;
                    }
                }
            }
        }
        for(auto i = 0; i != n; i++) {
            if(i != s - 1) {
                cout << distance[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
