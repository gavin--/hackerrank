#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

const int MOD = 1000000000;

int solve(int n, vector<int>* graph) {
    int dp[n];
    fill(dp, dp + n, 0);
    vector<int> current;
    set<int> path;
    vector<bool> visited(n), cycle(n);
    function<void(int)> dfs = [&n, &dfs, &graph, &visited, &cycle, &path, &dp, &current](int node) {
        visited[node] = true;
        current.emplace_back(node);
        if(node == n - 1) {
            for(auto i : current) {
                path.emplace(i);
                dp[i] = (dp[i] + 1) % MOD;
            }
        } else {
            for(auto i : graph[node]) {
                if(visited[i]) {
                    cycle[i] = true;
                } else {
                    if(dp[i] > 0) {
                        for(auto j : current) {
                            dp[j] = (dp[j] + dp[i]) % MOD;
                        }
                    } else if(dp[i] == 0) {
                        dfs(i);
                    }
                }
            }
        }
        if(dp[node] == 0) {
            dp[node] = -1;
        }
        current.pop_back();
        visited[node] = false;
    };
    dfs(0);
    for(int i = 0; i < n; i++) {
        if(cycle[i] && path.find(i) != path.end()) {
            return -1;
        }
    }
    return dp[0];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    for(int x, y; cin >> x >> y; graph[x - 1].emplace_back(y - 1)) {
    }
    auto result = solve(n, graph);
    if(result == -1) {
        cout << "INFINITE PATHS";
    } else {
        cout << result;
    }
    return 0;
}
