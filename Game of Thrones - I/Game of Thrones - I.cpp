#include <map>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> count;
    for(auto& i : s) {
        count[i]++;
    }
    auto mid = s.size() % 2 == 1;
    for(auto& i : count) {
        if(i.second % 2 == 1) {
            if(mid) {
                mid = false;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
