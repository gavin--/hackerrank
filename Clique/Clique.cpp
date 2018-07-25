#include <iostream>
using namespace std;

long long sq(long long n) {
    return n * n;
}

long long max_edge(long long n, long long r) {
    return (sq(n) - n % r * sq((n - 1) / r + 1) - (r - n % r) * sq(n / r)) / 2;
}

int main() {
    int t;
    cin >> t;
    for(long long n, m; cin >> n >> m; ) {
        long long begin = 2, end = n * n;
        while(begin < end) {
            auto mid = (begin + end) / 2;
            if(max_edge(n, mid) >= m) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        cout << begin << endl;
    }
    return 0;
}
