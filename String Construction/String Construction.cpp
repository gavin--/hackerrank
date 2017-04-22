#include <set>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(string s; cin >> s; ) {
        cout << set<char>(s.begin(), s.end()).size() << endl;
    }
    return 0;
}
