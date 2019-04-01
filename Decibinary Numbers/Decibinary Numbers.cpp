#include <iostream>
#include <algorithm>
using namespace std;

const int LENGTH = 20, SIZE = 285113;

int main() {
    long long *dp[LENGTH], sum[SIZE], q;
    for(int i = 0; i < LENGTH; i++) {
        dp[i] = new long long[SIZE];
    }
    dp[0][0] = 1;
    for(int i = 1; i < SIZE; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i < LENGTH; i++) {
        for(int j = 0; j < SIZE; j++) {
            dp[i][j] = 0;
            for(int k = 0; k <= 9; k++) {
                if(j - k * (1 << (i - 1)) >= 0) {
                    dp[i][j] += dp[i - 1][j - k * (1 << (i - 1))];
                }
            }
        }
    }
    sum[0] = 1;
    for(int i = 1; i < SIZE; i++) {
        sum[i] = sum[i - 1] + dp[LENGTH - 1][i];
    }
    cin >> q;
    for(long long x; cin >> x; ) {
        auto it = lower_bound(sum, sum + SIZE, x);
        x -= *prev(it);
        int target = distance(sum, it), length = 0;
        while(dp[length + 1][target] < x) {
            length++;
        }
        while(length >= 0) {
            long long current = 0;
            for(int i = 0; ; i++) {
                current += dp[length][target - (1 << length) * i];
                if(current >= x) {
                    cout << i;
                    x -= current - dp[length][target - (1 << length) * i];
                    target -= (1 << length) * i;
                    break;
                }
            }
            length--;
        }
        cout << endl;
    }
    return 0;
}
