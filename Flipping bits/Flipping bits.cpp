#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        unsigned int i;
        cin >> i;
        cout << ~i << endl;
    }
    return 0;
}
