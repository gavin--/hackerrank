#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long N, m, result = 0;
        cin >> N >> m;
        result += N / m * m * (m - 1) / 2;
        result += N % m * (N % m + 1) / 2;
        cout << result << endl;
    }
    return 0;
}
