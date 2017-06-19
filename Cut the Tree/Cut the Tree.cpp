#include <vector>
#include <forward_list>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

auto d = INT_MAX, sum = 0;

int dfs(int root, int parent, forward_list<int>* graph, short* data) {
    int result = data[root];
    for(auto& i : graph[root]) {
        if(i != parent) {
            auto temp = dfs(i, root, graph, data);
            d = min(d, abs(sum - temp - temp));
            result += temp;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    short data[n];
    for(auto i = 0; i != n; i++) {
        cin >> data[i];
        sum += data[i];
    }
    forward_list<int> graph[n];
    for(int a, b; cin >> a >> b; ) {
        graph[a - 1].emplace_front(b - 1);
        graph[b - 1].emplace_front(a - 1);
    }
    dfs(0, -1, graph, data);
    cout << d;
    return 0;
}
