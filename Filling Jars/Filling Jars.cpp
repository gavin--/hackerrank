#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    auto result = 0ll;
    for(int a, b, k; cin >> a >> b >> k; ) {
        result += (b - a + 1ll) * k;
    }
    cout << result / N;
    return 0;
}
