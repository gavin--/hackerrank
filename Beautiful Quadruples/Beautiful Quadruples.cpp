#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int input[4];
    cin >> input[0] >> input[1] >> input[2] >> input[3];
    sort(begin(input), end(input));
    map<int, int> count;
    auto total = 0;
    for(auto i = 1; i <= input[2]; i++) {
        for(auto j = i; j <= input[3]; j++) {
            count[i ^ j]++;
            total++;
        }
    }
    auto result = 0ll;
    for(auto i = 1; i <= input[1]; i++) {
        for(auto j = 1; j <= min(input[0], i); j++) {
            result += total - count[j ^ i];
        }
        for(auto j = i; j <= input[3]; j++) {
            count[i ^ j]--;
            total--;
        }
    }
    cout << result;
    return 0;
}
