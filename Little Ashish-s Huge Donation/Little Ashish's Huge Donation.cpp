#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long f(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long X;
        cin >> X;
        auto begin = 1ll, end = begin;
        while(f(end) < X) {
            begin = end;
            end *= 2;
        }
        while(begin < end) {
            auto mid = (begin + end + 1) / 2;
            if(f(mid) > X) {
                end = mid - 1;
            } else {
                begin = mid;
            }
        }
        cout << begin << endl;
    }
    return 0;
}
