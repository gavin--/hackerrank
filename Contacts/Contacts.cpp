#include <set>
#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    set<string> set;
    for(string operation, name; cin >> operation >> name; ) {
        if(operation == "add") {
            set.emplace(name);
        } else {
            auto find = set.lower_bound(name);
            auto count = 0;
            while(find != set.end() && (*find).compare(0, name.size(), name) == 0) {
                count++;
                find++;
            }
            cout << count << endl;
        }
    }
    return 0;
}
