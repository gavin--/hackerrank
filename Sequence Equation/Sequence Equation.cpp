#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n], result[n];
    for(auto i = 0; cin >> p[i]; i++) {
        p[i]--;
    }
    for(auto i = 0; i != n; i++) {
        result[p[p[i]]] = i + 1;
    }
    for(auto i = 0; i != n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
