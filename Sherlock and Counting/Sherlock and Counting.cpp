#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long n, k; cin >> n >> k; cout << endl) {
        auto begin = 1ll, end = n / 2;
        while(begin < end) {
            auto mid = (begin + end + 1) / 2;
            if(mid * (n - mid) <= n * k) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        if(end + end == n) {
            cout << n - 1;
        } else {
            cout << 2 * end;
        }
    }
    return 0;
}
