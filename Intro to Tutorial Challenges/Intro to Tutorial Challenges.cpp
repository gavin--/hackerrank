#include <iostream>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    for(auto i = 0; ; i++) {
        int j;
        cin >> j;
        if(j == V) {
            cout << i;
            break;
        }
    }
    return 0;
}
