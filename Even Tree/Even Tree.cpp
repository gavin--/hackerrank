#include <forward_list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int result = 0;

int dfs(int node, int parent, forward_list<int>* graph, int N) {
    auto current = 0;
    for(auto& i : graph[node]) {
        if(i != parent) {
            auto temp = dfs(i, node, graph, N) + 1;
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
    fill(graph, graph + N, forward_list<int>());
    for(int a, b; cin >> a >> b; ) {
        graph[a - 1].emplace_front(b - 1);
        graph[b - 1].emplace_front(a - 1);
    }
    dfs(0, -1, graph, N);
    cout << result;
    return 0;
}
