#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    N *= 2;
    auto smallest = N, largest = 0;
    vector<int> graph[N];
    for(int i, j; cin >> i >> j; ) {
        i--;
        j--;
        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
    }
    vector<bool> visited(N, false);
    for(auto i = 0; i != N; i++) {
        if(!visited[i]) {
            auto size = 0;
            visited[i] = true;
            stack<int> stack;
            stack.emplace(i);
            do {
                auto top = stack.top();
                stack.pop();
                size++;
                for(auto j : graph[top]) {
                    if(!visited[j]) {
                        visited[j] = true;
                        stack.emplace(j);
                    }
                }
            } while(!stack.empty());
            if(size < smallest && size != 1) {
                smallest = size;
            }
            if(size > largest && size != 1) {
                largest = size;
            }
        }
    }
    cout << smallest << ' ' << largest;
    return 0;
}
