#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count[100] = {};
    for(int i; cin >> i; ) {
        count[i]++;
    }
    for(auto i = 0; i < 100; i++) {
        cout << count[i] << ' ';
    }
    return 0;
}
