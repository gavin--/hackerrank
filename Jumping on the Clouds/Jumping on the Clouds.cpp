#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    vector<bool> c(istream_iterator<bool> {cin}, istream_iterator<bool> {});
    for(auto i = 0; i < n - 1; result++) {
        if(i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i++;
        }
    }
    cout << result;
    return 0;
}
