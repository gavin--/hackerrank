#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> t[n];
    for(int i = 0, j, k; cin >> j >> k; i++) {
        t[i] = pair<int, int>(j + k, i + 1);
    }
    sort(t, t + n);
    for(auto& i : t) {
        cout << i.second << ' ';
    }
    return 0;
}
