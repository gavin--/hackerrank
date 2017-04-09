#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(unsigned long long n; cin >> n; ) {
        auto louise = false;
        for(auto j = 1ull << 63; n > 1; louise = !louise) {
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
