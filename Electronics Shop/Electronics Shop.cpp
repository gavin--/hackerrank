#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int s, n, m, result = -1;
    cin >> s >> n >> m;
    int keyboard[n], usb[m];
    for(auto i = 0; i != n; i++) {
        cin >> keyboard[i];
    }
    for(auto i = 0; cin >> usb[i]; i++) {
    }
    sort(usb, usb + m);
    for(auto i = 0; i != n; i++) {
        auto begin = 0, end = m - 1;
        while(begin < end) {
            auto mid = (begin + end + 1) / 2;
            if(keyboard[i] + usb[mid] <= s) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        if(keyboard[i] + usb[end] <= s) {
            result = max(result, keyboard[i] + usb[end]);
        }
    }
    cout << result;
    return 0;
}
