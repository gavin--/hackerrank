#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(auto i = 1; i <= n; i++) {
        for(auto j = 1; j <= n - i; j++) {
            cout << ' ';
        }
        for(auto j = 1; j <= i; j++) {
            cout << '#';
        }
        cout << endl;
    }
    return 0;
}
