#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << max(0, *max_element(istream_iterator<int>(cin), istream_iterator<int>()) - k);
    return 0;
}
