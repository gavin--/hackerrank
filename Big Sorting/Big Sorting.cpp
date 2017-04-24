#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + n, [](string& left, string& right) {
        if(left.size() == right.size()) {
            return left < right;
        } else {
            return left.size() < right.size();
        }
    });
    for(auto i = 0; i != n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
