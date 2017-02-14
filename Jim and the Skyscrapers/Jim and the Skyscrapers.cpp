#include <stack>
#include <iostream>
using namespace std;

int main() {
    int N;
    auto result = 0ll;
    cin >> N;
    stack<int> stack;
    for(int h; cin >> h; ) {
        if(stack.empty() || h < stack.top()) {
            stack.emplace(h);
        } else {
            while(!stack.empty() && h > stack.top()) {
                auto same = 0ll;
                auto last = stack.top();
                while(!stack.empty() && last == stack.top()) {
                    same++;
                    stack.pop();
                }
                result += same * (same - 1);
            }
            stack.emplace(h);
        }
    }
    while(!stack.empty()) {
        auto same = 0ll;
        auto last = stack.top();
        while(!stack.empty() && last == stack.top()) {
            same++;
            stack.pop();
        }
        result += same * (same - 1);
    }
    cout << result;
    return 0;
}
