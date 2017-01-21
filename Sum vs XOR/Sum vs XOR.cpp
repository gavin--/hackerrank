#include <iostream>
using namespace std;

int main() {
    long long n, result = 1;
    cin >> n;
    while(n > 0) {
        if(n % 2 == 0) {
            result *= 2;
        }
        n /= 2;
    }
    cout << result;
    return 0;
}
