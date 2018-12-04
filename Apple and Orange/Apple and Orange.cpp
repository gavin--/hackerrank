#include <iostream>
using namespace std;

int main() {
    int s, t, a, b, m, n, apple = 0, orange = 0;
    cin >> s >> t >> a >> b >> m >> n;
    for(int j; m > 0; m--) {
        cin >> j;
        if(a + j >= s && a + j <= t) {
            apple++;
        }
    }
    for(int j; cin >> j; ) {
        if(b + j >= s && b + j <= t) {
            orange++;
        }
    }
    cout << apple << endl << orange;
    return 0;
}
