#include <stack>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[n], left[n], right[n], result[n + 1];
    fill(result, result + n + 1, INT_MAX);
    stack<int> s1, s2;
    for(auto i = 0; i != n; i++) {
        cin >> a[i];
        while(!s1.empty() && a[s1.top()] <= a[i]) {
            s1.pop();
        }
        if(s1.empty()) {
            left[i] = -1;
        } else {
            left[i] = s1.top();
        }
        s1.emplace(i);
        while(!s2.empty() && a[s2.top()] <= a[i]) {
            right[s2.top()] = i;
            s2.pop();
        }
        s2.emplace(i);
    }
    while(!s2.empty()) {
        right[s2.top()] = n;
        s2.pop();
    }
    for(int i = 0; i != n; i++) {
        int size = right[i] - left[i]  - 1;
        result[size] = min(result[size], a[i]);
    }
    for(int i = n - 1; i > 0; i--) {
        result[i] = min(result[i], result[i + 1]);
    }
    for(int d; cin >> d; cout << result[d] << endl) {
    }
    return 0;
}
