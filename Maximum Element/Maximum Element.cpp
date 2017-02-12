#include <stack>
#include <iostream>
using namespace std;

int main() {
    int N;
    stack<pair<int, int>> stack;
    for(cin >> N; N > 0; N--) {
        int type, x;
        cin >> type;
        switch(type) {
            case 1:
                int x;
                cin >> x;
                if(stack.empty()) {
                    stack.emplace(x, x);
                } else {
                    stack.emplace(x, max(x, stack.top().second));
                }
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << stack.top().second << endl;
        }
    }
    return 0;
}
