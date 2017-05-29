#include <climits>
#include <iostream>
using namespace std;

int main() {
    auto sum = 0ll;
    auto min = INT_MAX, max = 1;
    for(int i; cin >> i; sum += i) {
        if(i < min) {
            min = i;
        }
        if(i > max) {
            max = i;
        }
    }
    cout << sum - max << ' ' << sum - min;
    return 0;
}
