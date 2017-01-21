#include <forward_list>
#include <vector>
#include <iostream>
using namespace std;

int result = 0;

int dfs(int node, vector<bool>& visited, forward_list<int>* graph, int& N) {
    auto current = 0;
    for(auto& i : graph[node]) {
        if(visited[i] == false) {
            visited[i] = true;
            auto temp = dfs(i, visited, graph, N) + 1;
            if(temp % 2 == 0) {
                result++;
            }
            current += temp;
        }
    }
    return current;
}

int main() {
    int N, M;
    cin >> N >> M;
    forward_list<int> graph[N];
    for(int a, b; cin >> a >> b; ) {
        graph[a - 1].emplace_front(b - 1);
        graph[b - 1].emplace_front(a - 1);
    }
    vector<bool> visited(N);
    visited[0] = true;
    dfs(0, visited, graph, N);
    cout << result;
    return 0;
}
