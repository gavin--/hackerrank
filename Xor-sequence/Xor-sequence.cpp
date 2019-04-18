#include <iostream>
using namespace std;

long long sum(long long x) {
    long long r = x % 8;
    if(r == 0 || r == 1) {
        return x;
    }
    if(r == 2 || r == 3) {
        return 2;
    }
    if(r == 4 || r == 5) {
        return x + 2;
    }
    return 0;
}

int main() {
    int q;
    cin >> q;
    for(long long l, r; cin >> l >> r; cout << (sum(r) ^ sum(l - 1)) << endl) {
    }
    return 0;
}
