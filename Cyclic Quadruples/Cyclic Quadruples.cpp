#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long L1, R1, L2, R2, L3, R3, L4, R4;
        cin >> L1 >> R1 >> L2 >> R2 >> L3 >> R3 >> L4 >> R4;
        auto I1 = R1 - L1 + 1, I2 = R2 - L2 + 1, I3 = R3 - L3 + 1, I4 = R4 - L4 + 1;
        auto result = I1 * I2 % MOD * I3 % MOD * I4 % MOD;
        result = (result - max(min(R1, R2) - max(L1, L2) + 1, 0ll) * I3 % MOD * I4) % MOD;
        result = (result - max(min(R2, R3) - max(L2, L3) + 1, 0ll) * I1 % MOD * I4) % MOD;
        result = (result - max(min(R3, R4) - max(L3, L4) + 1, 0ll) * I1 % MOD * I2) % MOD;
        result = (result - max(min(R1, R4) - max(L1, L4) + 1, 0ll) * I2 % MOD * I3) % MOD;
        result = (result + max(min({R1, R2, R3}) - max({L1, L2, L3}) + 1, 0ll) * I4) % MOD;
        result = (result + max(min({R1, R2, R4}) - max({L1, L2, L4}) + 1, 0ll) * I3) % MOD;
        result = (result + max(min({R2, R3, R4}) - max({L2, L3, L4}) + 1, 0ll) * I1) % MOD;
        result = (result + max(min({R1, R3, R4}) - max({L1, L3, L4}) + 1, 0ll) * I2) % MOD;
        result = (result + max(min(R2, R3) - max(L2, L3) + 1, 0ll) * max(min(R1, R4) - max(L1, L4) + 1, 0ll)) % MOD;
        result = (result + max(min(R1, R2) - max(L1, L2) + 1, 0ll) * max(min(R3, R4) - max(L3, L4) + 1, 0ll)) % MOD;
        result = (result - 3 * (max(min({R1, R2, R3, R4}) - max({L1, L2, L3, L4}) + 1, 0ll))) % MOD;
        result = (result + MOD) % MOD;
        cout << result << endl;
    }
    return 0;
}
