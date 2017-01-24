#include <iostream>
#include <map>
using namespace std;

int main() {
    int p;
    for(cin >> p; p > 0; p--) {
        string a, b;
        cin >> a >> b;
        map<char, int> count;
        for(auto& i : a) {
            count[i]++;
        }
        bool common = false;
        for(auto& i : b) {
            if(count.find(i) != count.end()) {
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
