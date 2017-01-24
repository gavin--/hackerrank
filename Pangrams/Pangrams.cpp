#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    map<char, int> count;
    for(auto& i : s) {
        if(isalpha(i)) {
            count[tolower(i)]++;
        }
    }
    if(count.size() == 26) {
        cout << "pangram\n";
    } else {
        cout << "not pangram\n";
    }
    return 0;
}
