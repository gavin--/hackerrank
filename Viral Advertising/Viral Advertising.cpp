#include <iostream>
using namespace std;

int main() {
    int n, current = 5, result = 0;
    cin >> n;
    while(n > 0) {
        result += current / 2;
        current = current / 2 * 3;
        n--;
    }
    cout << result;
    return 0;
}
