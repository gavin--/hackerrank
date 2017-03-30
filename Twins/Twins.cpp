#include <vector>
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

int main() {
    int n, m, result = 0;
    cin >> n >> m;
    vector<bool> front(isqrt(m) + 1, 1), back(m - n + 1, 1);
    if(n == 1) {
        back[0] = 0;
    }
    for(auto i = 2; i * i < front.size(); i++) {
        if(front[i]) {
            for(auto j = i + i; j < front.size(); j += i) {
                front[j] = 0;
            }
        }
    }
    for(auto i = 2; i < front.size(); i++) {
        if(front[i]) {
            auto j = ((n - 1) / i + 1) * i;
            if(j == i) {
                j += i;
            }
            for(; j <= m; j += i) {
                back[j - n] = 0;
            }
        }
    }
    for(auto i = 2; i < back.size(); i++) {
        if(back[i] && back[i - 2]) {
            result++;
        }
    }
    cout << result;
    return 0;
}
