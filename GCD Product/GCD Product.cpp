#include <vector>
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long pow(long long x, long long n) {
    long long result = 1;
    while (n != 0) {
        if(n % 2 == 1) {
            result = result * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return result;
}

int main() {
    long long size[2];
    cin >> size[0] >> size[1];
    vector<bool> prime(size[0] + 1, 1);
    for (long long i = 2; i * i <= size[0]; i++) {
        if (prime[i]) {
            for (long long j = i * i; j <= size[0]; j += i) {
                prime[j] = 0;
            }
        }
    }
    long long result = 1;
    for (long long i = 2; i <= size[0]; i++) {
        if (prime[i]) {
            vector<long long> count[2];
            for (int k : {0, 1}) {
                auto j = i;
                while (j * i <= size[k]) {
                    j *= i;
                }
                for (long long sum = 0; j > 1; j /= i) {
                    count[k].emplace_back(size[k] / j - sum);
                    sum += count[k].back();
                }
            }
            long long exp = 0;
            for (long long i = 1; i <= count[0].size(); i++) {
                for (long long j = 1; j <= count[1].size(); j++) {
                    exp += min(i, j) * count[0][count[0].size() - i] * count[1][count[1].size() - j];
                }
            }
            result = pow(i, exp) * result % MOD;
        }
    }
    cout << result;
    return 0;
}
