#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> points[n];
    for(int i = 0; cin >> points[i].first >> points[i].second; i++) {
    }
    auto polar = [] (pair<int, int>& p1, pair<int, int>& p2) {
        int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
        if(y1 == 0) {
            if(x1 > 0) {
                if(y2 == 0 && x2 < x1 && x2 > 0) {
                    return false;
                }
                return true;
            }
            if(y2 < 0 || (y2 == 0 && x2 < x1)) {
                return true;
            }
            return false;
        }
        if(y2 == 0) {
            if(y1 > 0 && x2 < 0) {
                return true;
            }
            return false;
        }
        if(y1 > 0 && y2 < 0) {
            return true;
        }
        if(y1 < 0 && y2 > 0) {
            return false;
        }
        int left = y1 * x2, right = y2 * x1;
        if(left == right) {
            return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
        }
        return left < right;
    };
    sort(points, points + n, polar);
    for(auto& i : points) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}
