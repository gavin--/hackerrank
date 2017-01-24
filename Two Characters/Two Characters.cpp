#include <set>
#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    string s;
    cin >> n >> s;
    set<char> set;
    for(auto& i : s) {
        set.emplace(i);
    }
    for(auto& i : set) {
        for(auto& j : set) {
            if(i != j) {
                string copy;
                for(auto& k : s) {
                    if(k == i || k == j) {
                        copy.push_back(k);
                    }
                }
                bool t = true;
                for(auto k = 1; k != copy.size(); k++) {
                    if(copy[k] == copy[k - 1]) {
                        t = false;
                    }
                }
                if(t && copy.size() > result) {
                    result = copy.size();
                }
            }
        }
    }
    cout << result;
    return 0;
}
