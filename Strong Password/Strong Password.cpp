#include <iostream>
#include <set>
#include <cctype>
using namespace std;

const set<char> chars{'!', '@', '#', '$', '%', '^', '&', '*', '(', '\'', ')', '-', '+'};

int main() {
    int n, result = 0;
    cin >> n;
    string s;
    cin >> s;
    bool special = false, digit = false, lower = false, upper = false;
    for(auto i : s) {
        if(chars.find(i) != chars.end()) {
            special = true;
        } else if(islower(i)) {
            lower = true;
        } else if(isupper(i)) {
            upper = true;
        } else if(isdigit(i)) {
            digit = true;
        }
    }
    if(!special) {
        s.push_back(*chars.begin());
        result++;
    }
    if(!lower) {
        s.push_back('a');
        result++;
    }
    if(!upper) {
        s.push_back('A');
        result++;
    }
    if(!digit) {
        s.push_back('0');
        result++;
    }
    if(s.size() < 6) {
        result += 6 - s.size();
    }
    cout << result;
    return 0;
}
