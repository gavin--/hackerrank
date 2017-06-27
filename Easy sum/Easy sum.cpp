#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long N, m; cin >> N >> m; cout << N / m * m * (m - 1) / 2 + N % m * (N % m + 1) / 2 << endl) {
    }
    return 0;
}
