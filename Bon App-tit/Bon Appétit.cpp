#include <iostream>
using namespace std;

int main() {
    int n, k, sum = 0, charged;
    cin >> n >> k;
    for(int i = 0, price; i < n; i++) {
        cin >> price;
        if(i != k) {
            sum += price;
        }
    }
    cin >> charged;
    if(sum / 2 == charged) {
        cout << "Bon Appetit";
    } else {
        cout << charged - sum / 2;
    }
    return 0;
}
