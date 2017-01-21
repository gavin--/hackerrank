#include <map>
#include <iostream>
using namespace std;

int main() {
    int N, result = 0;
    cin >> N;
    map<int, int> A, B;
    for(auto i = 0; i != N; i++) {
        int j;
        cin >> j;
        A[j]++;
    }
    for(int j; cin >> j ; ) {
        auto find = A.find(j);
        if(find != A.end()) {
            result++;
            if(find->second == 1) {
                A.erase(find);
            } else {
                find->second--;
            }
        }
    }
    if(result < N) {
        cout << result + 1;
    } else {
        cout << result - 1;
    }
    return 0;
}
