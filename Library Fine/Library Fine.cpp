#include <iostream>
using namespace std;

int main() {
    int Da, Ma, Ya, De, Me, Ye;
    cin >> Da >> Ma >> Ya >> De >> Me >> Ye;
    if(Ya < Ye) {
        cout << 0;
    } else if(Ya == Ye) {
        if(Ma < Me) {
            cout << 0;
        } else if(Ma == Me) {
            if(Da <= De) {
                cout << 0;
            } else {
                cout << 15 * (Da - De);
            }
        } else {
            cout << 500 * (Ma - Me);
        }
    } else {
        cout << 10000;
    }
    return 0;
}
