#include <map>
#include <iostream>
using namespace std;

int main() {
    map<int, int> map;
    int n;
    cin >> n;
    for(int m; cin >> m; ) {
        string d;
        cin >> d;
        auto current = 0, base = 1;
        for(auto it = d.rbegin(); it != d.rend(); it++, base *= m) {
            auto digit = *it - '0';
            if(digit >= m) {
                goto next;
            }
            current += digit * base;
        }
        map[current]++;
        next:
            ;
    }
    auto result = 0ll;
    for(auto& i : map) {
        result += i.second * (i.second - 1ll) / 2;
    }
    cout << result;
    return 0;
}
