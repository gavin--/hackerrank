#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        long long K;
        cin >> K;
        cout << (K / 2) * ((K - 1) / 2 + 1) << endl;
    }
    return 0;
}
