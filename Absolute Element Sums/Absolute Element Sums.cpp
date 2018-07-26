#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long prefix[n + 1], sum = 0;
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    cin >> q;
    for(long long x; cin >> x; ) {
        sum += x;
        int begin = 0, end = n - 1;
        while(begin < end) {
            auto mid = (begin + end) / 2 + 1;
            if(a[mid] + sum < 0) {
                begin = mid;
            } else {
                end = mid - 1;
            }
        }
        if(a[begin] + sum >= 0) {
            begin = -1;
        }
        long long result = prefix[n] - prefix[begin + 1] + sum * (n - begin - 1) - (prefix[begin + 1] + sum * (begin + 1));
        cout << result << endl;
    }
    return 0;
}
