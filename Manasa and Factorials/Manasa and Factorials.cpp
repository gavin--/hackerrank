#include <iostream>
using namespace std;

long long count5(long long n) {
    auto result = 0ll;
    for(auto i = 5ll; i <= n; i *= 5) {
        result += n / i;
    }
    return result;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long n, five = 0, begin = 1ll, end = begin;
        cin >> n;
        while(count5(end) < n) {
            end *= 2;
        }
        while(begin < end) {
            auto mid = (begin + end) / 2;
            if(count5(mid) < n) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        cout << end << endl;
    }
    return 0;
}
