#include <iostream>
using namespace std;

int main() {
    int Size;
    cin >> Size;
    int Arr[Size];
    for(auto i = 0; cin >> Arr[i]; i++) {
    }
    auto i = Size - 1, k = Arr[i];
    for(; i > 0 && k < Arr[i - 1]; i--) {
        Arr[i] = Arr[i - 1];
        for(auto& j : Arr) {
            cout << j << ' ';
        }
        cout << endl;
    }
    Arr[i] = k;
    for(auto& j : Arr) {
        cout << j << ' ';
    }
    cout << endl;
    return 0;
}
