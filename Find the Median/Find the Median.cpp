#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    nth_element(a, a + n / 2, a + n);
    cout << a[n / 2];
    return 0;
}
