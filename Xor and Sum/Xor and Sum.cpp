#include <iostream>
#include <algorithm>
using namespace std;
 
const int D = 314159, MOD = 1000000007;
 
int main() {
    string a, b;
    cin >> a >> b;
    auto c = max(a.size(), b.size()) - 1;
    reverse(begin(b), end(b));
    for(auto i = b.size(); i <= c; i++) {
        b.push_back('0');
    }
    reverse(begin(a), end(a));
    for(auto i = a.size(); i <= c; i++) {
        a.push_back('0');
    }
    int sum[c + 1];
    sum[0] = b[0] - '0';
    for(auto i = 1; i <= c; i++) {
        sum[i] = sum[i - 1] + b[i] - '0';
    }
    auto ans = 0;
    long long pow[D + c + 1];
    pow[0] = 1;
    for(auto i = 1; i <= D + c; i++) {
        pow[i] = (pow[i - 1] * 2) % MOD;
    }
    for(auto i = 0; i <= c; i++) {
        if(a[i] == '0') {
            ans = (ans + sum[i] * pow[i]) % MOD;
        } else {
        	ans = (ans + (D - sum[i] + 1) * pow[i]) % MOD;
        }
    }
    ans = (ans + sum[c] * pow[c + 1] % MOD * (pow[D - c] - 1 + MOD) % MOD) % MOD;
    for(auto i = 0; i < c; i++) {
        ans = (ans + (sum[c] - sum[i]) * pow[D + 1 + i]) % MOD;
    }
    cout << ans;
    return 0;
}
