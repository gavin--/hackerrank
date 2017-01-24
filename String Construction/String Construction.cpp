#include <set>
#include <iostream>
using namespace std;

int main() {
    int n;
    for(cin >> n; n > 0; n--) {
        string s;
        cin >> s;
        set<char> set;
        for(auto& i : s) {
            set.emplace(i);
        }
        cout << set.size() << endl;
    }
    return 0;
}
