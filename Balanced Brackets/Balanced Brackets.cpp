#include <stack>
#include <iostream>
using namespace std;

string check(string& s) {
    stack<char> stack;
    for(auto& i : s) {
        if(i == ')') {
            if(stack.empty() || stack.top() != '(') {
                return "NO\n";
            }
            stack.pop();
        } else if(i == ']') {
            if(stack.empty() || stack.top() != '[') {
                return "NO\n";
            }
            stack.pop();
        } else if(i == '}') {
            if(stack.empty() || stack.top() != '{') {
                return "NO\n";
            }
            stack.pop();
        } else {
            stack.emplace(i);
        }
    }
    if(stack.empty()) {
        return "YES\n";
    } else {
        return "NO\n";
    }
}

int main() {
    int n;
    for(cin >> n; n > 0; n--) {
        string s;
        cin >> s;
        cout << check(s);
    }
    return 0;
}
