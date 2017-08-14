#include <iostream>
#include <climits>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(int n; cin >> n; ) {
        pair<int, int> points[n];
        int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
            minx = min(minx, points[i].first);
            maxx = max(maxx, points[i].first);
            miny = min(miny, points[i].second);
            maxy = max(maxy, points[i].second);
        }
        string result = "YES\n";
        for(int i = 0; i < n; i++) {
            if(points[i].first != minx && points[i].first != maxx) {
                if(points[i].second != miny && points[i].second != maxy) {
                    result = "NO\n";
                }
            }
        }
        cout << result;
    }
    return 0;
}
