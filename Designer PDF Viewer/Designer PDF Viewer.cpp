#include <map>
#include <iostream>
using namespace std;

int main() {
    map<char, int> map;
    for(auto i = 'a'; i <= 'z'; i++) {
        int j;
        cin >> j;
        map[i] = j;
    }
    auto tallest = 0;
    string s;
    cin >> s;
    for(auto& i : s) {
        tallest = max(map[i], tallest);
    }
    cout << s.size() * tallest;
    return 0;
}
