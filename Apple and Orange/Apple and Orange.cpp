#include <iostream>
using namespace std;

int main() {
    int s, t, a, b, m, n, apple = 0, orange = 0;
    cin >> s >> t >> a >> b >> m >> n;
    for(auto i = 0; i != m; i++) {
        int j;
        cin >> j;
        if(a + j >= s && a + j <= t) {
            apple++;
        }
    }
    for(auto i = 0; i != n; i++) {
        int j;
        cin >> j;
        if(b + j >= s && b + j <= t) {
            orange++;
        }
    }
    cout << apple << endl << orange;
    return 0;
}
