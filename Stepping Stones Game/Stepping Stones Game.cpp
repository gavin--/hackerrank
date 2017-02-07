#include <iostream>
using namespace std;

long long isqrt(long long n) {
    auto begin = 1ll, end = n / 2 + 1;
    while(begin < end) {
        auto mid = (begin + end + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return begin;
}

string check(long long N) {
    auto det = isqrt(1 + 8 * N);
    if(det * det != 1 + 8 * N || det % 2 == 0) {
        return "Better Luck Next Time\n";
    }
    return "Go On Bob " + to_string((det - 1) / 2) + "\n";
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long N;
        cin >> N;
        cout << check(N);
    }
    return 0;
}
