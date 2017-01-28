#include <iostream>
using namespace std;

const long long MOD = 1000000007, INVERSE = 111111112;

long long pow(long long n, long long x) {
    auto result = 1;
    while(x > 0) {
        if(x % 2 == 1) {
            result = (result * n) % MOD;
        }
        n = (n * n) % MOD;
        x /= 2;
    }
    return result;
}

int main() {
    string N;
    cin >> N;
    auto result = 0ll;
    for(auto i = 0; i != N.size(); i++) {
        auto count = (i + 1) * (N[i] - '0');
        result = (result + count * (pow(10, N.size() - i) - 1) % MOD * INVERSE) % MOD;
    }
    cout << result;
    return 0;
}
