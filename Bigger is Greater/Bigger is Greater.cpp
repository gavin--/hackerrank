#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string w; cin >> w; ) {
        if(next_permutation(begin(w), end(w))) {
            cout << w << endl;
        } else {
            cout << "no answer\n";
        }
    }
    return 0;
}
