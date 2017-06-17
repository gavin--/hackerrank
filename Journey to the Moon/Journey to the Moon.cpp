#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    int N, I;
    cin >> N >> I;
    vector<int> graph[N], country;
    for(int a, b; cin >> a >> b; ) {
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<bool> visited(N);
    for(auto i = 0; i != N; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            stack<int> stack;
            stack.emplace(i);
            auto size = 0;
            do {
                auto top = stack.top();
                size++;
                stack.pop();
                for(auto& j : graph[top]) {
                    if(visited[j] == false) {
                        visited[j] = true;
                        stack.emplace(j);
                    }
                }
            } while(!stack.empty());
            country.emplace_back(size);
        }
    }
    int sum[country.size() + 1];
    sum[0] = 0;
    for(auto i = 1; i <= country.size(); i++) {
        sum[i] = sum[i - 1] + country[i - 1];
    }
    auto result = 0ll;
    for(auto i = 0; i != country.size(); i++) {
        result += country[i] * sum[i];
    }
    cout << result;
    return 0;
}
