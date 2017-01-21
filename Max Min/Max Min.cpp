#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int x[N];
    for(auto i = 0; cin >> x[i]; i++) {
    }
    sort(x, x + N);
    auto unfair = INT_MAX;
    for(auto i = K - 1; i < N; i++) {
        unfair = min(unfair, x[i] - x[i - K + 1]);
    }
    cout << unfair;
    return 0;
}
