#include <stack>
#include <iostream>
using namespace std;

int main() {
    int n;
    long long result = 0;
    cin >> n;
    stack<int> stack;
    for(int h; cin >> h; ) {
        while(!stack.empty() && h > stack.top()) {
            long long same = 0;
            int last = stack.top();
            while(!stack.empty() && last == stack.top()) {
                same++;
                stack.pop();
            }
            result += same * (same - 1);
        }
        stack.emplace(h);
    }
    while(!stack.empty()) {
        long long same = 0;
        int last = stack.top();
        while(!stack.empty() && last == stack.top()) {
            same++;
            stack.pop();
        }
        result += same * (same - 1);
    }
    cout << result;
    return 0;
}
