#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(long long B, W, X, Y, Z; cin >> B >> W >> X >> Y >> Z; cout << B * min(X, Y + Z) + W * min(Y, X + Z) << endl) {
    }
    return 0;
}
