#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N; cin >> N; ) {
        int B[N];
        for(auto i = 0; i != N; i++) {
            cin >> B[i];
        }
        pair<long long, long long> dp = {0, 0};
        for(auto i = 1; i != N; i++) {
            dp = {max(dp.first, dp.second + B[i - 1] - 1), max(dp.first + B[i] - 1, dp.second + abs(B[i] - B[i - 1]))};
        }
        cout << max(dp.first, dp.second) << endl;
    }
    return 0;
}
