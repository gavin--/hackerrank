#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int SIZE = 101;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> n; ) {
        vector<int> graph[SIZE];
        for(int i = 1; i < SIZE; i++) {
            for(int j = i + 1; j < min(i + 7, SIZE); j++) {
                graph[i].emplace_back(j);
            }
        }
        for(int from, to; n > 0; n--) {
            cin >> from >> to;
            for(int j = 1; j < SIZE; j++) {
                for(auto& k : graph[j]) {
                    if(k == from) {
                        k = to;
                    }
                }
            }
        }
        cin >> m;
        for(int from, to; m > 0; m--) {
            cin >> from >> to;
            for(int j = 1; j < SIZE; j++) {
                for(auto& k : graph[j]) {
                    if(k == from) {
                        k = to;
                    }
                }
            }
        }
        vector<bool> visited(SIZE);
        visited[1] = true;
        queue<int> queue;
        queue.emplace(1);
        int distance = 0;
        do {
            for(auto size = queue.size(); size > 0; size--) {
                if(queue.front() == SIZE - 1) {
                    goto next;
                }
                for(auto i : graph[queue.front()]) {
                    if(!visited[i]) {
                        visited[i] = true;
                        queue.emplace(i);
                    }
                }
                queue.pop();
            }
            distance++;
        } while(!queue.empty());
        cout << -1 << endl;
        continue;
        next:
        cout << distance << endl;
    }
    return 0;
}
