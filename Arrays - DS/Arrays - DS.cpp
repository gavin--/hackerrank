#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(auto i = 0; cin >> a[i]; i++) {
    }
    for(auto i = n - 1; i >= 0; i--) {
        cout << a[i] << ' ';
    }
    return 0;
}
