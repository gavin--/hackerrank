#include <map>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    auto result = 0;
    map<char, int> counta, countb;
    for(auto& i : a) {
        counta[i]++;
    }
    for(auto& i : b) {
        countb[i]++;
    }
    for(auto& i : b) {
        auto find = counta.find(i);
        if(find == counta.end()) {
            result++;
        } else {
            if(find->second == 1) {
                counta.erase(find);
            } else {
                find->second--;
            }
        }
    }
    for(auto& i : a) {
        auto find = countb.find(i);
        if(find == countb.end()) {
            result++;
        } else {
            if(find->second == 1) {
                countb.erase(find);
            } else {
                find->second--;
            }
        }
    }
    cout << result;
    return 0;
}
