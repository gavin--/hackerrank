#include <map>
#include <iostream>
using namespace std;

bool valid(map<int, int>& map) {
    if(map.size() == 1) {
        return true;
    }
    if(map.size() == 2) {
        auto first = begin(map);
        auto last = map.rbegin();
        if(first->first == 1 && first->second == 1) {
            return true;
        }
        if(last->second == 1 && last->first == first->first + 1) {
            return true;
        }
    }
    return false;
}

int main() {
    string S;
    cin >> S;
    map<char, int> count;
    for(auto& i : S) {
        count[i]++;
    }
    map<int, int> map;
    for(auto& i : count) {
        map[i.second]++;
    }
    if(valid(map)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
