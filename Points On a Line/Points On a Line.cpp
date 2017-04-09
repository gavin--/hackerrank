#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    short lastx, lasty;
    auto h = true, v = true;
    cin >> lastx >> lasty;
    for(short x, y; cin >> x >> y; lastx = x, lasty = y) {
        if(x != lastx) {
            v = false;
        }
        if(y != lasty) {
            h = false;
        }
    }
    if(h || v) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
