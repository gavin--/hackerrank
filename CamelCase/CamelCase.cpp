#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int camel = 1;
    for(auto& i : s) {
        if(isupper(i)) {
            camel++;
        }
    }
    cout << camel;
    return 0;
}
