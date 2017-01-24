#include <map>
#include <iostream>
using namespace std;

bool remove(map<int, int>& size) {
    if(size.size() == 1) {
        return true;
    }
    if(size.size() == 2) {
        auto first = begin(size);
        auto second = next(begin(size));
        if(first->first == 1 && first->second == 1) {
            return true;
        }
        if(second->second == 1 && second->first == first->first + 1) {
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
    map<int, int> size;
    for(auto& i : count) {
        size[i.second]++;
    }
    if(remove(size)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
