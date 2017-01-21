#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int V[n];
    for(auto i = 0; cin >> V[i]; i++) {
    }
    sort(V, V + n);
    for(auto& i : V) {
        cout << i << ' ';
    }
    return 0;
}
