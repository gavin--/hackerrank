#include <stack>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[n], left[n], right[n], result[n + 1];
    for(auto i = 0; i != n; i++) {
        cin >> a[i];
    }
    stack<int> stack;
    for(auto i = 0; i != n; i++) {
        while(!stack.empty() && a[stack.top()] < a[i]) {
            right[stack.top()] = i;
            stack.pop();
        }
        stack.emplace(i);
    }
    while(!stack.empty()) {
        right[stack.top()] = n;
        stack.pop();
    }
    for(auto i = n - 1; i >= 0; i--) {
        while(!stack.empty() && a[stack.top()] < a[i]) {
            left[stack.top()] = i;
            stack.pop();
        }
        stack.emplace(i);
    }
    while(!stack.empty()) {
        left[stack.top()] = -1;
        stack.pop();
    }
    fill(result, result + n + 1, INT_MAX);
    for(auto i = 0; i != n; i++) {
        auto size = right[i] - left[i]  - 1;
        result[size] = min(result[size], a[i]);
    }
    for(auto i = n - 1; i > 0; i--) {
        result[i] = min(result[i], result[i + 1]);
    }
    for(int d; cin >> d; cout << result[d] << endl) {
    }
    return 0;
}
