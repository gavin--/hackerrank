#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K, result = 0;
    cin >> N >> K;
    int a[N];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    sort(a, a + N);
    for(auto i = 0; i < N - 1; i++) {
        auto begin = i + 1, end = N - 1;
        while(begin < end) {
            auto mid = (end + begin) / 2;
            if(a[mid] - a[i] < K) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        if(a[begin] - a[i] == K) {
            result++;
        }
    }
    cout << result;
    return 0;
}
