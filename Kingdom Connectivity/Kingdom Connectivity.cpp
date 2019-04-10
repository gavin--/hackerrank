#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

const int MOD = 1000000000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n], current;
    int dp[n];
    fill(dp, dp + n, 0);
    for(int x, y; cin >> x >> y; graph[x - 1].emplace_back(y - 1)) {
    }
    function<bool(int)> cycle = [&current, &graph, &dp](int n) {
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
                return true;
            }
        }
        return false;
    };
    if(cycle(n)) {
        cout << "INFINITE PATHS";
    } else {
        cout << dp[0];
    }
    return 0;
}
