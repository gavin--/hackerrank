#include <iostream>
#include <forward_list>
#include <array>
using namespace std;

const long long MOD = 1000000007;

void dfs(int current, int parent, array<long long, 2>* dp, forward_list<int>* graph) {
    dp[current] = {0, 1};
    for(auto& i : graph[current]) {
        if(i != parent) {
            dfs(i, current, dp, graph);
            dp[current] = {(dp[current][0] * (dp[i][0] * 2 + dp[i][1]) + dp[current][1] * (dp[i][0] + dp[i][1])) % MOD, dp[current][1] * dp[i][0] % MOD};
        }
    }
}

int main() {
    int n;
    cin >> n;
    forward_list<int> graph[n];
    fill(graph, graph + n, forward_list<int>());
    for(int i, j; cin >> i >> j; ) {
        graph[i - 1].emplace_front(j - 1);
        graph[j - 1].emplace_front(i - 1);
    }
    array<long long, 2> dp[n];
    dfs(0, -1, dp, graph);
    cout << dp[0][0] * 2 % MOD;
    return 0;
}
