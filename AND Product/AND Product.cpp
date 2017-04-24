#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(unsigned long long a, b; cin >> a >> b; ) {
        auto c = ULLONG_MAX;
        b ^= a;
        do {
            b /= 2;
            c *= 2;
        } while (b != 0);
        cout << (a & c) << endl;
    }
    return 0;
}
