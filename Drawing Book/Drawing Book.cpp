#include <iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    cout << min(p / 2, (n - p) / 2);
    return 0;
}
