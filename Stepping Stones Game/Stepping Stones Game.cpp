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

void check(long long N) {
    auto det = isqrt(1 + 8 * N);
    if(det * det != 1 + 8 * N || det % 2 == 0) {
        cout << "Better Luck Next Time\n";
    } else {
        cout << "Go On Bob " << (det - 1) / 2 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for(long long N; cin >> N; check(N)) {
    }
    return 0;
}
