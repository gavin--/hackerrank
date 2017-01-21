#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, P, Q, result, mini = 0;
    cin >> N;
    int A[N];
    for(auto i = 0; i != N; i++) {
        cin >> A[i];
    }
    cin >> P >> Q;
    sort(A, A + N);
    auto lower = lower_bound(A, A + N, P);
    if(lower != A + N) {
        auto current = *lower - P;
        if(lower != A) {
            current = min(current, P - *(lower - 1));
        }
        if(current > mini) {
            result = P;
            mini = current;
        }
    } else {
        auto current = P - A[N - 1];
        if(current > mini) {
            result = P;
            mini = current;
        }
    }
    for(auto i = 1; i != N; i++) {
        auto mid = (A[i] + A[i - 1]) / 2;
        if(mid >= P && mid <= Q) {
            auto current = min(A[i] - mid, mid - A[i - 1]);
            if(current > mini) {
                result = mid;
                mini = current;
            }
        }
    }
    lower = lower_bound(A, A + N, Q);
    if(lower != A + N) {
        auto current = *lower - Q;
        if(lower != A) {
            current = min(current, Q - *(lower - 1));
        }
        if(current > mini) {
            result = Q;
            mini = current;
        }
    } else {
        auto current = Q - A[N - 1];
        if(current > mini) {
            result = Q;
            mini = current;
        }
    }
    cout << result;
    return 0;
}
