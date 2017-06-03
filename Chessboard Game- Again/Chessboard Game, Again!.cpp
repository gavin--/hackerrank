#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char grundy[15][15];

int mex(int x, int y) {
    vector<int> set;
    if(x - 2 >= 0) {
        if(y - 1 >= 0) {
            if(grundy[x - 2][y - 1] != -1) {
                set.emplace_back(grundy[x - 2][y - 1]);
            } else {
                set.emplace_back(mex(x - 2, y - 1));
            }
        }
        if(y < 14) {
            if(grundy[x - 2][y + 1] != -1) {
                set.emplace_back(grundy[x - 2][y + 1]);
            } else {
                set.emplace_back(mex(x - 2, y + 1));
            }
        }
    }
    if(y - 2 >= 0) {
        if(x < 14) {
            if(grundy[x + 1][y - 2] != -1) {
                set.emplace_back(grundy[x + 1][y - 2]);
            } else {
                set.emplace_back(mex(x + 1, y - 2));
            }
        }
        if(x - 1 >= 0) {
            if(grundy[x - 1][y - 2] != -1) {
                set.emplace_back(grundy[x - 1][y - 2]);
            } else {
                set.emplace_back(mex(x - 1, y - 2));
            }
        }
    }
    auto result = 0;
    sort(begin(set), end(set));
    if(set.empty() || set[0] != 0) {
        return 0;
    }
    for(auto i = 1; i < set.size(); i++) {
        if(set[i] != set[i - 1] + 1 && set[i] != set[i - 1]) {
            return set[i - 1] + 1;
        }
    }
    return set[set.size() - 1] + 1;
}

int main() {
    int T;
    cin >> T;
    for(auto i = 0; i < 15; i++) {
        fill(begin(grundy[i]), end(grundy[i]), -1);
    }
    for(auto i = 0; i < 15; i++) {
        for(auto j = 0; j < 15; j++) {
            grundy[i][j] = mex(i, j);
        }
    }
    for(int k; cin >> k; ) {
        auto result = 0;
        while(k > 0) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            result = result ^ grundy[x][y];
            k--;
        }
        if(result != 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
