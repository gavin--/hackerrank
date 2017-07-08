#include <iostream>
#include <array>
using namespace std;

int main() {
    array<array<int, 3>, 3> magic[] = {
        {{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}},
        {{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}},
        {{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}}},
        {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}}},
        {{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}},
        {{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}},
        {{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}},
        {{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}}},
    };
    array<array<int, 3>, 3> s;
    for(auto i = 0; i < 3; i++) {
        for(auto j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }
    int result = 81;
    for(auto i = 0; i < 8; i++) {
        int current = 0;
        for(auto j = 0; j < 3; j++) {
            for(auto k = 0; k < 3; k++) {
                current += abs(s[j][k] - magic[i][j][k]);
            }
        }
        result = min(result, current);
    }
    cout << result;
    return 0;
}
