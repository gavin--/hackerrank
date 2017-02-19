#include <iostream>
#include <set>
using namespace std;

char grundy[15][15];

int mex(int x, int y) {
    set<int> set;
    if(x - 2 >= 0) {
        if(y - 1 >= 0) {
            if(grundy[x - 2][y - 1] != -1) {
                set.emplace(grundy[x - 2][y - 1]);
            } else {
                set.emplace(mex(x - 2, y - 1));
            }
        }
        if(y < 14) {
            if(grundy[x - 2][y + 1] != -1) {
                set.emplace(grundy[x - 2][y + 1]);
            } else {
                set.emplace(mex(x - 2, y + 1));
            }
        }
    }
    if(y - 2 >= 0) {
        if(x < 14) {
            if(grundy[x + 1][y - 2] != -1) {
                set.emplace(grundy[x + 1][y - 2]);
            } else {
                set.emplace(mex(x + 1, y - 2));
            }
        }
        if(x - 1 >= 0) {
            if(grundy[x - 1][y - 2] != -1) {
                set.emplace(grundy[x - 1][y - 2]);
            } else {
                set.emplace(mex(x - 1, y - 2));
            }
        }
    }
    auto result = 0;
    while(set.count(result) == 1) {
        result++;
    }
    return result;
}

int main() {
    int T;
    for(auto i = 0; i < 15; i++) {
        fill(begin(grundy[i]), end(grundy[i]), -1);
    }
    for(auto i = 0; i < 15; i++) {
        for(auto j = 0; j < 15; j++) {
            grundy[i][j] = mex(i, j);
        }
    }
    for(cin >> T; T > 0; T--) {
        int k, result = 0;
        cin >> k;
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
