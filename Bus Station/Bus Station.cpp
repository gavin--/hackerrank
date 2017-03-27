#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    auto sum = 0ll, prefix = 0ll;
    for(auto i = 0; cin >> a[i]; i++) {
        sum += a[i];
    }
    for(auto i = 0; ; i++) {
        prefix += a[i];
        if(prefix > sum / 2) {
            break;
        }
        if(sum % prefix == 0) {
            auto current = 0ll;
            for(auto j = i + 1; j < n; j++) {
                current += a[j];
                if(current > prefix) {
                    break;
                }
                if(current == prefix) {
                    current = 0;
                }
            }
            if(current == 0) {
                cout << prefix << ' ';
            }
        }
    }
    cout << sum;
    return 0;
}
