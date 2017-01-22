#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int rating[N], dp[N];
    for(auto i = 0; cin >> rating[i]; i++) {
    }
    dp[0] = 1;
    for(auto i = 1; i < N; i++) {
        if(rating[i] > rating[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
    }
    for(auto i = N - 2; i >= 0; i--) {
        if(rating[i] > rating[i + 1] && dp[i] <= dp[i + 1]) {
            dp[i] = dp[i + 1] + 1;
        }
    }
    auto sum = 0ll;
    for(auto& i : dp) {
        sum += i;
    }
    cout << sum;
    return 0;
}
