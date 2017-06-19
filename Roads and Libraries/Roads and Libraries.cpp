#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int n, m, clib, croad; cin >> n >> m >> clib >> croad; ) {
        auto result = 0ll;
        vector<int> graph[n];
        fill(graph, graph + n, vector<int>());
        for(auto i = 0; i != m; i++) {
            int j, k;
            cin >> j >> k;
            graph[j - 1].emplace_back(k - 1);
            graph[k - 1].emplace_back(j - 1);
        }
        vector<bool> visited(n);
        for(auto i = 0; i != n; i++) {
            if(visited[i] == false) {
                auto current = 0ll;
                visited[i] = true;
                stack<int> stack;
                stack.emplace(i);
                do {
                    auto top = stack.top();
                    stack.pop();
                    current++;
                    for(auto& j : graph[top]) {
                        if(visited[j] == false) {
                            visited[j] = true;
                            stack.emplace(j);
                        }
                    }
                } while(!stack.empty());
                result += min((current - 1) * croad + clib, current * clib);
            }
        }
        cout << result << endl;
    }
    return 0;
}
