#include <iostream>
using namespace std;

int reverse(int i) {
    auto result = 0;
    while(i != 0) {
        result = result * 10 + i % 10;
        i /= 10;
    }
    return result;
}

int main() {
    int i, j, k, result = 0;
    cin >> i >> j >> k;
    for(auto x = i; x <= j; x++) {
        if(abs(x - reverse(x)) % k == 0) {
            result++;
        }
    }
    cout << result;
    return 0;
}
