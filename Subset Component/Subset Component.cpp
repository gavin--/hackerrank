#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long d[n];
    for(auto i = 0; cin >> d[i]; i++) {
    }
    auto result = 64;
    for(auto i = 1ull, size = 1ull << n; i < size; i++) {
        vector<unsigned long long> v;
        for(auto j = 0; j < n; j++) {
            if((1ull << j) & i) {
                v.emplace_back(d[j]);
            }
        }
        auto mask = 0ull;
        for(auto i = 0; i < v.size(); i++) {
            for(auto j = i + 1; j < v.size(); j++) {
                if(v[i] & v[j]) {
                    v[j] = v[i] | v[j];
                    v[i] = 0;
                    break;
                }
            }
            mask |= v[i];
            if(v[i] != 0) {
                result++;
            }
        }
        result += 64 - bitset<64>(mask).count();
    }
    cout << result;
    return 0;
}
