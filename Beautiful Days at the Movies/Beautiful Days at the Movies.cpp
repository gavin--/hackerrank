#include <vector>
#include <iostream>
using namespace std;

int reverse(int i) {
    vector<int> v;
    while(i != 0) {
        v.emplace_back(i % 10);
        i /= 10;
    }
    auto result = 0;
    for(auto i = 0, j = 1; i != v.size(); i++, j *= 10) {
        result += v.rbegin()[i] * j;
    }
    return result;
}

int main() {
    int i, j, k, result = 0;
    cin >> i >> j >> k;
    for(auto x = i; x <= j; x++) {
        if(abs(x - reverse(x)) % k == 0) {
            result++;
        }
    }
    cout << result;
    return 0;
}
