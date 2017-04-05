#include <iostream>
using namespace std;

int main() {
    int n, max = 0, result = 0;
    cin >> n;
    for(int h; cin >> h; ) {
        if(h > max) {
            max = h;
            result = 1;
        } else if(h == max) {
            result++;
        }
    }
    cout << result;
    return 0;
}
