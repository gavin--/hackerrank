#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, result = 0;
    cin >> n >> m;
    vector<bool> x[n];
    fill(x, x + n, vector<bool>(m));
    for(auto i = 0; i != n; i++) {
        for(auto j = 0; j != m; j++) {
            bool k;
            cin >> k;
            x[i][j] = k;
        }
    }
    for(auto i = 0; i != n; i++) {
        for(auto j = 0; j != m; j++) {
            if(x[i][j]) {
                auto current = 0;
                x[i][j] = 0;
                stack<pair<int, int>> stack;
                stack.emplace(i, j);
                while(!stack.empty()) {
                    auto top = stack.top();
                    stack.pop();
                    current++;
                    result = max(result, current);
                    for(auto k = -1; k <= 1; k++) {
                        for(auto l = -1; l <= 1; l++) {
                            if(top.first + k >= 0 && top.first + k < n && top.second + l >= 0 && top.second < m) {
                                if(x[top.first + k][top.second + l]) {
                                    x[top.first + k][top.second + l] = 0;
                                    stack.emplace(top.first + k, top.second + l);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << result;
    return 0;
}
