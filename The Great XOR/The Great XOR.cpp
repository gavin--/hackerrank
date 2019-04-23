#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int q;
    cin >> q;
    for(long long x; cin >> x; ) {
        bitset<64> bits(x);
        long long length = 0;
        for(long long i = 0; i < 64; i++) {
            if(bits[i]) {
                length = i + 1;
            }
        }
        cout << (1ll << length) - 1 - x << endl;
    }
    return 0;
}
