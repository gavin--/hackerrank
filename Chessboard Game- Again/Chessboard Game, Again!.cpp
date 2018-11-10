#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int grundy[15][15];

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
    for(int i = 0; i < set.size(); i++) {
        while(set[i] < set.size() && set[set[i]] != set[i]) {
            swap(set[set[i]], set[i]);
        }
    }
    for(int i = 0; i < set.size(); i++) {
        if(set[i] != i) {
            return i;
        }
    }
    return set.size();
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < 15; i++) {
        fill(begin(grundy[i]), end(grundy[i]), -1);
    }
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            grundy[i][j] = mex(i, j);
        }
    }
    for(int k; cin >> k; ) {
        int result = 0;
        for(int x, y; k > 0; k--) {
            cin >> x >> y;
            result = result ^ grundy[x - 1][y - 1];
        }
        if(result != 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}
