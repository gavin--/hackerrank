#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points[6];
    for(int x, y; cin >> x >> y; ) {
        if(x > 0) {
            if(y >= 0) {
                points[0].emplace_back(x, y);
            } else {
                points[5].emplace_back(x, y);
            }
        } else if(x == 0) {
            if(y > 0) {
                points[1].emplace_back(x, y);
            } else {
                points[4].emplace_back(x, y);
            }
        } else {
            if(y >= 0) {
                points[2].emplace_back(x, y);
            } else {
                points[3].emplace_back(x, y);
            }
        }
    }
    auto polar = [] (pair<int, int> p1, pair<int, int> p2) {
        auto left = p1.second * p2.first, right = p2.second * p1.first;
        if(left == right) {
            return p1.first * p1.first + p1.second * p1.second < p2.first * p2.first + p2.second * p2.second;
        }
        return left < right;
    };
    for(auto& i : points) {
        sort(begin(i), end(i), polar);
        for(auto& j : i) {
            cout << j.first << ' ' << j.second << endl;
        }
    }
    return 0;
}
