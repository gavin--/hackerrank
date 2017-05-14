#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<long long, int> p[n];
    for(auto i = 0; cin >> p[i].first; i++) {
        p[i].second = i;
    }
    sort(p, p + n);
    auto result = LLONG_MAX;
    for(auto i = 1; i != n; i++) {
        if(p[i].second < p[i - 1].second) {
            result = min(result, p[i].first - p[i - 1].first);
        }
    }
    cout << result;
    return 0;
}
