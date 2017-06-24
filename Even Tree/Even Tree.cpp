#include <forward_list>
#include <iostream>
using namespace std;

int dfs(int node, int parent, forward_list<int>* graph, int& result) {
    auto current = 0;
    for(auto& i : graph[node]) {
        if(i != parent) {
            auto temp = dfs(i, node, graph, result) + 1;
            if(temp % 2 == 0) {
                result++;
            }
            current += temp;
        }
    }
    return current;
}

int main() {
    int N, M, result = 0;
    cin >> N >> M;
    forward_list<int> graph[N];
    for(int a, b; cin >> a >> b; ) {
        graph[a - 1].emplace_front(b - 1);
        graph[b - 1].emplace_front(a - 1);
    }
    dfs(0, -1, graph, result);
    cout << result;
    return 0;
}
