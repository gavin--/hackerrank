#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    auto result = 1ll;
    while(n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int A;
    cin >> A;
    auto result = pow(2, A);
    while(cin >> A) {
        auto exp = pow(2, A);
        result = (result + exp * result + exp) % MOD;
    }
    cout << result;
    return 0;
}
