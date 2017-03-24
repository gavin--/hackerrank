#include <vector>
#include <iostream>
using namespace std;

const int size = 9734;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<bool> primes(size, 1);
    for(auto i = 2; i * i < size; i++) {
        if(primes[i]) {
            for(auto j = i * i; j < size; j += i) {
                primes[j] = 0;
            }
        }
    }
    int prime[Q];
    for(auto i = 0, j = 2; i != Q; i++, j++) {
        while(!primes[j]) {
            j++;
        }
        prime[i] = j;
    }
    vector<int> A;
    for(int i; cin >> i; ) {
        A.emplace_back(i);
    }
    for(auto i = 0; i < Q; i++) {
        vector<int> temp, B;
        for(int j = A.size() - 1; j >= 0; j--) {
            if(A[j] % prime[i] == 0) {
                B.emplace_back(A[j]);
            } else {
                temp.emplace_back(A[j]);
            }
        }
        for(int i = B.size() - 1; i >= 0; i--) {
            cout << B[i] << endl;
        }
        swap(A, temp);
    }
    for(int i = A.size() - 1; i >= 0; i--) {
        cout << A[i] << endl;
    }
    return 0;
}
