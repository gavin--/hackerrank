#include <iostream>
using namespace std;

int main(){
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    for(auto i = 0; i < n; i++){
        for(auto j = 0; j < n; j++){
            int a;
            cin >> a;
            if(i == j) {
                sum1 += a;
            }
            if(i + j == n - 1) {
                sum2 += a;
            }
        }
    }
    cout << abs(sum1 - sum2);
    return 0;
}
