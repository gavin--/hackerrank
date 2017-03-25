#include <iostream>
#include <algorithm>
using namespace std;

const long long product[] = {1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230, 200560490130, 7420738134810, 304250263527210, 13082761331670030, 614889782588491410};

int main() {
    int q;
    cin >> q;
    for(long long n; cin >> n; ) {
        auto it = upper_bound(begin(product), end(product), n);
        cout << it - begin(product) - 1 << endl;
    }
    return 0;
}
