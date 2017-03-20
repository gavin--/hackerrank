#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        unsigned long long n;
        bool louise = false;
        for(cin >> n; n > 1; louise = !louise) {
            auto j = 1ull << 63;
            while(j > n) {
                j /= 2;
            }
            if(j == n) {
                n /= 2;
            } else {
                n -= j;
            }
        }
        if(louise) {
            cout << "Louise\n";
        } else {
            cout << "Richard\n";
        }
    }
    return 0;
}
