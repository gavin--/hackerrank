#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10000001;

long long lowbit(long long i) {
    return i & -i;
}

long long get(vector<long long>& bit, long long index) {
    long long result = 0;
    while(index > 0) {
        result += bit[index];
        index -= lowbit(index);
    }
    return result;
}

void add(vector<long long>& bit, long long index, long long val) {
    while(index < bit.size()) {
        bit[index] += val;
        index += lowbit(index);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int n; scanf("%d", &n) > 0; ) {
        long long a[n], result = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        vector<long long> bit(SIZE, 0);
        for(int i = n - 1; i >= 0; i--) {
            result += get(bit, a[i] - 1);
            add(bit, a[i], 1);
        }
        printf("%lld\n", result);
    }
    return 0;
}
