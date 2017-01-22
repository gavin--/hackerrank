#include <iostream>
using namespace std;

int solve(int begin, int end, long long sum[]) {
    for(auto i = begin; i != end; i++) {
        if(sum[i + 1] == sum[end + 1] - sum[i + 1] + sum[begin]) {
            return max(solve(begin, i, sum), solve(i + 1, end, sum)) + 1;
        }
    }
    return 0;
}

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N, result = 0;
        cin >> N;
        long long sum[N + 1];
        sum[0] = 0;
        for(auto i = 0; i != N; i++) {
            cin >> sum[i + 1];
            sum[i + 1] += sum[i];
        }
        cout << solve(0, N - 1, sum) << endl;
    }
    return 0;
}
