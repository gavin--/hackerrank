#include <set>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<string> set1;
    set<string, greater<string>> set2;
    string result = "GOOD SET";
    for(string s; cin >> s; ) {
        auto find1 = set1.lower_bound(s), find2 = set2.lower_bound(s);
        if(find1 == set1.end() || (*find1).substr(0, s.size()) != s) {
            set1.emplace(s);
        } else {
            result = "BAD SET\n" + s;
            break;
        }
        if(find2 == set2.end() || s.substr(0, (*find2).size()) != *find2) {
            set2.emplace(s);
        } else {
            result = "BAD SET\n" + s;
            break;
        }
    }
    cout << result;
    return 0;
}
