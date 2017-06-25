#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, result;
    cin >> n;
    int t[n], count[n];
    fill(count, count + n, 0);
    for(auto i = 0; cin >> t[i]; i++) {
        count[(i + 1) % n]++;
        count[(i - t[i] + n + 1) % n]--;
    }
    for(auto i = 0, sum = 0, max = -1; i < n; i++) {
        sum += count[i];
        if(sum > max) {
            max = sum;
            result = i + 1;
        }
    }
    cout << result;
    return 0;
}
