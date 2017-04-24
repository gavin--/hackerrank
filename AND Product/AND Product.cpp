#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(long long a, b; cin >> a >> b; ) {
        auto c = LLONG_MAX;
        b ^= a;
        while(b >>= 1) {
            c <<= 1;
        }
        cout << (a & c) << endl;
    }
    return 0;
}
