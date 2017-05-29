#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k, j = 0, result = 0;
    cin >> n >> k;
    vector<bool> c(istream_iterator<bool> {cin}, istream_iterator<bool> {});
    for(auto i = 0, last = -1; i != n; i++) {
        if(i - j >= k) {
            if(last == -1 || last - j >= k) {
                result = -1;
                break;
            }
            j = last + k;
            result++;
        }
        if(c[i]) {
            last = i;
        }
    }
    if(j < n && result >= 0) {
        result++;
    }
    cout << result;
    return 0;
}
