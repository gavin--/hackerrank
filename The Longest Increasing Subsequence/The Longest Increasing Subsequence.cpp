#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int nums[N];
    for(auto i = 0; cin >> nums[i]; i++) {
    }
    int dp[N], result = 0;
    dp[0] = nums[0];
    for(auto i = 1; i < N; i++) {
        if(nums[i] > dp[result]) {
            result++;
            dp[result] = nums[i];
        }
        else {
            auto low = 0, high = result;
            while(low < high) {
                auto mid = (low + high) / 2;
                if(dp[mid] >= nums[i]) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            dp[low] = nums[i];
        }
    }
    cout << result + 1;
    return 0;
}
