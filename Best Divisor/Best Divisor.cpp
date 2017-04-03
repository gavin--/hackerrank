#include <iostream>
using namespace std;

int digitsum(int n) {
    auto result = 0;
    while(n != 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    auto result = n, sum = digitsum(n);
    for(auto i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            auto d = digitsum(i);
            if(d > sum || (d == sum && i < result)) {
                sum = d;
                result = i;
            }
            d = digitsum(n / i);
            if(d > sum || (d == sum && n / i < result)) {
                sum = d;
                result = n / i;
            }
        }
    }
    cout << result;
    return 0;
}
