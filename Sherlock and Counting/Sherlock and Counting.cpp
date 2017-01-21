#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long n, k;
        cin >> n >> k;
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
            cout << 2 * end - 1;
        } else {
            cout << 2 * end;
        }
        cout << endl;
    }
    return 0;
}
