#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int g;
    for(cin >> g; g > 0; g--) {
        bool bob = false;
        int n;
        cin >> n;
        pair<int, int> a[n];
        for(auto i = 0; i != n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n, greater<pair<int, int>>());
        for(auto i = 0, end = n; i != n; i++) {
            if(a[i].second < end) {
                end = a[i].second;
                bob = !bob;
            }
        }
        if(bob) {
            cout << "BOB\n";
        } else {
            cout << "ANDY\n";
        }
    }
    return 0;
}
