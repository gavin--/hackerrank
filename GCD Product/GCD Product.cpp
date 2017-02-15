#include <vector>
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
    long long N, M;
    cin >> N >> M;
	vector<bool> prime(N + 1, 1);
	for(auto i = 2; i * i <= N; i++) {
		if(prime[i]) {
			for(auto j = i * i; j <= N; j += i) {
				prime[j] = 0;
			}
		}
	}
    auto result = 1ll;
    for(auto i = 2ll; i <= N; i++) {
        if(prime[i]) {
            auto j = i;
            while(j * i <= N) {
                j *= i;
            }
            vector<long long> s, t;
            for(auto sum = 0; j > 1 ; j /= i) {
                s.emplace_back(N / j - sum);
                sum += s.back();
            }
            j = i;
            while(j * i <= M) {
                j *= i;
            }
            for(auto sum = 0; j > 1 ; j /= i) {
                t.emplace_back(M / j - sum);
                sum += t.back();
            }
            auto exp = 0ll;
            for(auto i = 1; i <= s.size(); i++) {
                for(auto j = 1; j <= t.size(); j++) {
                    exp += min(i, j) * s[s.size() - i] * t[t.size() - j];
                }
            }
            result = pow(i, exp) * result % MOD;
        }
    }
    cout << result;
    return 0;
}
