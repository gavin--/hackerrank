#include <iostream>
using namespace std;

int main() {
    long long N, result = 0, sum = 0;
    cin >> N;
    int a[N];
    for(auto i = 0ll; cin >> a[i]; i++) {
        result += (i + 1) * a[i];
        sum += a[i];
    }
    auto current = result;
    for(auto i = 0; i < N; i++) {
        current -= sum;
        current += N * a[i];
        result = max(result, current);
    }
    cout << result;
    return 0;
}
