#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for(auto i = 0; cin >> p[i]; i++) {
        p[i]--;
    }
    for(auto i = 0; i != n; i++) {
        for(auto j = 0; j != n; j++) {
            if(p[p[j]] == i) {
                cout << j + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
