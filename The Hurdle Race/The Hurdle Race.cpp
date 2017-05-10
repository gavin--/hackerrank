#include <iostream>
using namespace std;

int main() {
    int n, k, result = 0;
    cin >> n >> k;
    for(int i; cin >> i; result = max(result, i)) {
    }
    cout << max(0, result - k);
    return 0;
}
