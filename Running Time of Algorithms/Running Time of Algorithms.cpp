#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], result = 0;
    for(int i = 0; cin >> a[i]; i++) {
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                result++;
            }
        }
    }
    cout << result;
    return 0;
}
