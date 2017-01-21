#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, m = INT_MAX;
    cin >> N;
    int a[N];
    for(int i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + N);
    for(auto i = 1; i < N; i++) {
        m = min(m, abs(a[i] - a[i - 1]));
    }
    for(auto i = 1; i < N; i++) {
        if(abs(a[i] - a[i - 1]) == m) {
            cout << a[i - 1] << ' ' << a[i] << ' ';
        }
    }
    return 0;
}
