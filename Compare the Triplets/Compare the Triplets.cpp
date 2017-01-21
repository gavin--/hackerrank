#include <iostream>

using namespace std;

int main(){
    int a0, a1, a2, b0, b1, b2;
    cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
    auto A = 0, B = 0;
    if(a0 > b0) {
        A++;
    } else if(b0 > a0) {
        B++;
    }
    if(a1 > b1) {
        A++;
    } else if(b1 > a1) {
        B++;
    }
    if(a2 > b2) {
        A++;
    } else if(b2 > a2) {
        B++;
    }
    cout << A << ' ' << B;
    return 0;
}
