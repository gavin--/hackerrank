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
    auto mid = [] (pair<int, int> p1, pair<int, int> p2) {
        return p1.second * p1.second < p2.second * p2.second;
    };
    sort(points[0].begin(), points[0].end(), polar);
    sort(points[1].begin(), points[1].end(), mid);
    sort(points[2].begin(), points[2].end(), polar);
    sort(points[3].begin(), points[3].end(), polar);
    sort(points[4].begin(), points[4].end(), mid);
    sort(points[5].begin(), points[5].end(), polar);
    for(auto& i : points) {
        for(auto& j : i) {
            cout << j.first << ' ' << j.second << endl;
        }
    }
    return 0;
}
