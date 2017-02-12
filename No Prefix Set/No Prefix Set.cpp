#include <set>
#include <iostream>
using namespace std;

int main() {
    int N;
    set<string> set1;
    set<string, greater<string>> set2;
    for(cin >> N; N > 0; N--) {
        string s;
        cin >> s;
        auto find1 = set1.lower_bound(s);
        auto find2 = set2.lower_bound(s);
        if(find1 == set1.end() || (*find1).substr(0, s.size()) != s) {
            set1.emplace(s);
        } else {
            cout << "BAD SET\n" << s;
            return 0;
        }
        if(find2 == set2.end() || s.substr(0, (*find2).size()) != *find2) {
            set2.emplace(s);
        } else {
            cout << "BAD SET\n" << s;
            return 0;
        }
    }
    cout << "GOOD SET";
    return 0;
}
