#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    auto sum = 0ll;
    for(int i; cin >> i; ) {
        v.emplace_back(i);
        sum += i;
    }
    pair<long long, long long> result = {sum, 0};
    for(auto& i : v) {
        result = {min(result.first, sum - i), max(result.second, sum - i)};
    }
    cout << result.first << ' ' << result.second;
    return 0;
}
