#include <iostream>
using namespace std;

int main(){
    int A[6][6], result = -9 * 7;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> A[i][j];
            if (i >= 2 && j >= 2) {
                int sum = A[i - 2][j - 2] + A[i - 2][j - 1] + A[i - 2][j];
                sum += A[i][j - 2] + A[i][j - 1] + A[i][j];
                sum += A[i - 1][j - 1];
                result = max(result, sum);
            }
        }
    }
    cout << result;
    return 0;
}
