#include <set>
#include <iostream>
using namespace std;

int main() {
    string s;
    size_t result = 0, n;
    cin >> n >> s;
    set<char> set(s.begin(), s.end());
    for(auto& i : set) {
        for(auto& j : set) {
            if(i != j) {
                string t;
                for(auto& k : s) {
                    if(k == i || k == j) {
                        t.push_back(k);
                    }
                }
                auto alternating = true;
                for(auto k = 1; k != t.size(); k++) {
                    if(t[k] == t[k - 1]) {
                        alternating = false;
                    }
                }
                if(alternating && t.size() > result) {
                    result = t.size();
                }
            }
        }
    }
    cout << result;
    return 0;
}
