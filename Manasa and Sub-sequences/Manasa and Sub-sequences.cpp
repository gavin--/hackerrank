#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    string S;
    cin >> S;
    auto result = 0ll, dp = 1ll;
    for(auto i = 0; i < S.size(); i++) {
        result = ((11 * result) + dp * (S[i] - '0')) % MOD;
        dp = (dp * 2) % MOD;
    }
    cout << result;
    return 0;
}
