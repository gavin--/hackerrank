#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, result = 0;
    cin >> N >> K;
    int c[N];
    for(auto i = 0; cin >> c[i]; i++) {
    }
    sort(c, c + N);
    for(auto i = 0; i < N / 2; i++) {
        swap(c[i], c[N - 1 - i]);
    }
    for(auto i = 0; i < N; i++) {
        result += c[i] *(i / K + 1);
    }
    cout << result;
    return 0;
}
