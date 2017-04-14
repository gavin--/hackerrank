#include <iostream>
#include <set>
using namespace std;

int main() {
    int p;
    cin >> p;
    for(string a, b; cin >> a >> b; ) {
        set<char> set;
        for(auto& i : a) {
            set.emplace(i);
        }
        auto common = false;
        for(auto& i : b) {
            if(set.find(i) != end(set)) {
                common = true;
                break;
            }
        }
        if(common) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
