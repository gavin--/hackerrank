#include <iostream>
using namespace std;

int main(){
    int A[6][6], result = -9 * 7;
    for(auto i = 0; i < 6; i++) {
        for(auto j = 0; j < 6; j++) {
            cin >> A[i][j];
        }
    }
    for(auto i = 0; i < 4; i++) {
        for(auto j = 0; j < 4; j++) {
            auto sum = A[i][j] + A[i][j + 1] + A[i][j + 2];
            sum += A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2];
            sum += A[i + 1][j + 1];
            result = max(result, sum);
        }
    }
    cout << result;
    return 0;
}
