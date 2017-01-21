#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    pair<int, int> op[2 * M];
    for(int i = 0, a, b, k; cin >> a >> b >> k; i += 2) {
        op[i] = pair<int, int>(a, k);
        op[i + 1] = pair<int, int>(b + 1, -k);
    }
    sort(op, op + 2 * M);
    auto sum = 0ll, result = 0ll;
    for(auto& i : op) {
        sum += i.second;
        result = max(sum, result);
    }
    cout << result;
    return 0;
}
