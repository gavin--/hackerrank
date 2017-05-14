#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool divide(long long x, long long y, long long x1, long long y1, long long x2, long long y2) {
    if((y - y1) * (x2 - x1) - (y2 - y1) * (x - x1) < 0) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    long long x[N], y[N], v[N];
    vector<pair<int, int>> result;
    for(auto i = 0; cin >> x[i] >> y[i] >> v[i]; i++) {
    }
    for(auto i = 0; i != N; i++) {
        for(auto j = i + 1; j != N; j++) {
            auto left = 0ll, right = 0ll;
            for(auto k = 0; k != N; k++) {
                if(k != i && k != j) {
                    if(divide(x[k], y[k], x[i], y[i], x[j], y[j])) {
                        left += v[k];
                    } else {
                        right += v[k];
                    }
                }
            }
            pair<int, int> c[4];
            c[0] = {abs(right + v[i] + v[j] - left), min(right + v[i] + v[j], left)};
            c[1] = {abs(right + v[i] - left - v[j]), min(right + v[i], left + v[j])};
            c[2] = {abs(right - left - v[i] - v[j]), min(right, left + v[j] + v[i])};
            c[3] = {abs(right + v[j] - left - v[i]), min(right + v[j], left + v[i])};
            result.emplace_back(*min_element(begin(c), end(c)));
        }
    }
    cout << min_element(begin(result), end(result))->second;
    return 0;
}
