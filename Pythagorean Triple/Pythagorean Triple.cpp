#include <iostream>
#include <array>
using namespace std;

int main() {
    long long a;
    cin >> a;
    array<long long, 3> result;
    result[0] = a;
    if(a % 2 == 1) {
        result[1] = (a * a + 1) / 2;
        result[2] = (a * a - 1) / 2;
    } else {
        result[1] = (a * a) / 4 + 1;
        result[2] = (a * a) / 4 - 1;
    }
    cout << result[0] << ' ' << result[1] << ' ' << result[2];
    return 0;
}
