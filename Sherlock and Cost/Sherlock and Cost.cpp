#include <iostream>
#include <array>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int B[N];
        for(auto i = 0; i != N; i++) {
            cin >> B[i];
        }
        array<long long, 2> dp = {0, 0};
        for(auto i = 1; i != N; i++) {
            dp = {max(dp[0], dp[1] + B[i - 1] - 1), max(dp[0] + B[i] - 1, dp[1] + abs(B[i] - B[i - 1]))};
        }
        cout << max(dp[0], dp[1]) << endl;
    }
    return 0;
}
