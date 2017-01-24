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
    bool mid = false;
    for(auto& i : count) {
        if(i.second % 2 == 1) {
            if(s.size() % 2 == 1 && mid == false) {
                mid = true;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
