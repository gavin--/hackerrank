#include <iostream>
using namespace std;

int main() {
    long long r, c;
    cin >> r >> c;
    auto result = (r - 1) / 2 * 10 + 2 * (c - 1);
    if((r - 1) % 2 == 1) {
        result++;
    }
    cout << result;
    return 0;
}
