#include <iostream>
#include <set>
using namespace std;

int main() {
    int p;
    cin >> p;
    for(string a, b; cin >> a >> b; ) {
        set<char> set(a.begin(), a.end());
        auto result = "NO\n";
        for(auto& i : b) {
            if(set.find(i) != end(set)) {
                result = "YES\n";
                break;
            }
        }
        cout << result;
    }
    return 0;
}
