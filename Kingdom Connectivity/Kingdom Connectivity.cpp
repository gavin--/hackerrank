#include <iostream>
#include <vector>
#include <set>
using namespace std;

int *dp;
vector<int> current;
const int MOD = 1000000000;

void dfs(int node, int n, vector<int> *graph, vector<bool>& visited, vector<bool>& cycle, set<int>& path) {
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
                    dfs(i, n, graph, visited, cycle, path);
                }
            }
        }
    }
    if(dp[node] == 0) {
        dp[node] = -1;
    }
    current.pop_back();
    visited[node] = false;
}

bool cycle(int n, vector<int> *graph) {
    set<int> path;
    vector<bool> visited(n), cycle(n);
    dfs(0, n, graph, visited, cycle, path);
    for(int i = 0; i < n; i++) {
        if(cycle[i] && path.find(i) != path.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    dp = new int[n]();
    for(int x, y; cin >> x >> y; graph[x - 1].emplace_back(y - 1)) {
    }
    if(cycle(n, graph)) {
        cout << "INFINITE PATHS";
    } else {
        cout << dp[0];
    }
    return 0;
}
