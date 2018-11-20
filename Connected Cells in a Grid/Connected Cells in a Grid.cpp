#include <stack>
#include <iostream>
using namespace std;

int main() {
    int n, m, result = 0;
    cin >> n >> m;
    bool x[n][m];
    for(int i = 0; i != n; i++) {
        for(int j = 0; j != m; j++) {
            cin >> x[i][j];
        }
    }
    for(int i = 0; i != n; i++) {
        for(int j = 0; j != m; j++) {
            if(x[i][j]) {
                auto current = 0;
                x[i][j] = false;
                stack<pair<int, int>> stack;
                stack.emplace(i, j);
                do {
                    auto top = stack.top();
                    stack.pop();
                    current++;
                    result = max(result, current);
                    for(auto k = -1; k <= 1; k++) {
                        for(auto l = -1; l <= 1; l++) {
                            if(top.first + k >= 0 && top.first + k < n && top.second + l >= 0 && top.second + l < m) {
                                if(x[top.first + k][top.second + l]) {
                                    x[top.first + k][top.second + l] = false;
                                    stack.emplace(top.first + k, top.second + l);
                                }
                            }
                        }
                    }
                } while(!stack.empty());
            }
        }
    }
    cout << result;
    return 0;
}
