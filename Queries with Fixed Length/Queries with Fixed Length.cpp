#include <stack>
#include <vector>
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
    for(auto i = n - 1; i >= 0; i--) {
        while(!stack.empty() && a[stack.top()] <= a[i]) {
            stack.pop();
        }
        if(stack.empty()) {
            right[i] = n;
        } else {
            right[i] = stack.top();
        }
        stack.emplace(i);
    }
    while(!stack.empty()) {
        stack.pop();
    }
    for(auto i = 0; i < n; i++) {
        while(!stack.empty() && a[stack.top()] <= a[i]) {
            stack.pop();
        }
        if(stack.empty()) {
            left[i] = -1;
        } else {
            left[i] = stack.top();
        }
        stack.emplace(i);
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
