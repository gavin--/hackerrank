#include <set>
#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    set<string> set;
    for(cin >> n; n > 0; n--) {
        string operation, name;
        cin >> operation >> name;
        if(operation == "add") {
            set.emplace(name);
        } else {
            auto find = set.lower_bound(name);
            auto count = 0;
            while(find != set.end() && (*find).substr(0, name.size()) == name) {
                count++;
                find++;
            }
            cout << count << endl;
        }
    }
    return 0;
}
