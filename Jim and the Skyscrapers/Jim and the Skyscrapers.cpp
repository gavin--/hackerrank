#include <stack>
#include <iostream>
using namespace std;

int main() {
    int n;
    long long result = 0;
    cin >> n;
    stack<int> stack;
    for(int h; cin >> h; stack.emplace(h)) {
        while(!stack.empty() && h > stack.top()) {
            long long same = 1;
            int last = stack.top();
            stack.pop();
            while(!stack.empty() && last == stack.top()) {
                same++;
                stack.pop();
            };
            result += same * (same - 1);
        }
    }
    while(!stack.empty()) {
        long long same = 1;
        int last = stack.top();
        stack.pop();
        while(!stack.empty() && last == stack.top()) {
            same++;
            stack.pop();
        };
        result += same * (same - 1);
    }
    cout << result;
    return 0;
}
