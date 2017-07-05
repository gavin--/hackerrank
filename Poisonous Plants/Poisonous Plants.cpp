#include <stack>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    stack<pair<int, int>> stack;
    for(int P; cin >> P; ) {
        int count = 1;
        while(!stack.empty() && stack.top().first >= P) {
            count = max(count, stack.top().second + 1);
            stack.pop();
        }
        if(!stack.empty()) {
            count = -1;
        }
        result = max(result, count);
        stack.emplace(P, count);
    }
    cout << result;
    return 0;
}
