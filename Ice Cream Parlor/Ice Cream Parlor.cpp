#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n, m; cin >> m >> n; ) {
        pair<int, int> c[n];
        for(auto i = 0; i < n; i++) {
            cin >> c[i].first;
            c[i].second = i + 1;
        }
        sort(c, c + n);
        for(auto i = 0; i < n - 1; i++) {
            auto t = m - c[i].first;
            auto it = lower_bound(c + i + 1, c + n, pair<int, int> {t, 0});
            if(it != c + n && it->first == t) {
                if(c[i].second < it->second) {
                    cout << c[i].second << ' ' << it->second << endl;
                } else {
                    cout << it->second << ' ' << c[i].second << endl;
                }
                break;
            }
        }
    }
    return 0;
}
