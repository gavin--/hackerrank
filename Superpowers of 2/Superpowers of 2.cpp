#include <iostream>
using namespace std;

int main() {
    long long a, b, x = 2;
    for(cin >> a >> b; a > 0; a--) {
        x = x * x % b;
    }
    cout << x;
    return 0;
}
