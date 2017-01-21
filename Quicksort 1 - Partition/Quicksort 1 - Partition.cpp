#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    for(auto i = 0; cin >> ar[i]; i++) {
    }
    auto p = ar[0];
    auto it = std::partition(ar + 1, ar + n, [&p](int i){return i < p;});
    copy(ar + 1, it, ostream_iterator<int>(cout, " "));
    cout << p << ' ';
    copy(it, ar + n, ostream_iterator<int>(cout, " "));
    return 0;
}
