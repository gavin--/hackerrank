#include <set>
#include <iostream>
using namespace std;

int main() {
    int T;
    set<int> x, y;
    for(cin >> T; T > 0; T--) {
        int a, b;
        cin >> a >> b;
        x.emplace(a);
        y.emplace(b);
    }
    cout << (long long)(*x.begin()) * (*y.begin()); 
    return 0;
}
