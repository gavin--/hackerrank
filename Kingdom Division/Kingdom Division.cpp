#include <iostream>
#include <forward_list>
using namespace std;

const long long MOD = 1000000007;

void dfs(int current, int parent, pair<long long, long long>* dp, forward_list<int>* graph) {
    dp[current] = {0, 1};
    for(auto& i : graph[current]) {
        if(i != parent) {
            dfs(i, current, dp, graph);
            dp[current] = {(dp[current].first * (dp[i].first * 2 + dp[i].second) + dp[current].second * (dp[i].first + dp[i].second)) % MOD, dp[current].second * dp[i].first % MOD};
        }
    }
}

int main() {
    int n;
    cin >> n;
    forward_list<int> graph[n];
    for(int i, j; cin >> i >> j; ) {
        i--;
        j--;
        graph[i].emplace_front(j);
        graph[j].emplace_front(i);
    }
    pair<long long, long long> dp[n];
    dfs(0, -1, dp, graph);
    cout << dp[0].first * 2 % MOD;
    return 0;
}
