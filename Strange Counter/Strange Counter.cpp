#include <iostream>
using namespace std;

int main() {
    long long t, i = 3, sum = 3;
    cin >> t;
    while(sum < t) {
        i *= 2;
        sum += i;
    }
    cout << sum - t + 1;
    return 0;
}
