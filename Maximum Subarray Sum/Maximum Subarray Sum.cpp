#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(long long n, m; cin >> n >> m; ) {
        pair<long long, int> sum[n];
        for(auto i = 0ll, j = 0ll; i != n; i++) {
            long long k;
            cin >> k;
            j = (j + k) % m;
            sum[i] = {j, i};
        }
        sort(sum, sum + n);
        auto result = sum[n - 1].first;
        for(auto i = 1; i < n; i++) {
            if(sum[i - 1].second > sum[i].second) {
                result = max(result, m - sum[i].first + sum[i - 1].first);
            }
        }
        cout << result << endl;
    }
    return 0;
}
