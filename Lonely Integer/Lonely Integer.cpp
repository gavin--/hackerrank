#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    for(int i; cin >> i; result ^= i) {
    }
    cout << result;
    return 0;
}
