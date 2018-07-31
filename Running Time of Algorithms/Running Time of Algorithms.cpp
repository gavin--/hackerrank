#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10001;

int lowbit(int i) {
    return i & -i;
}

int get(vector<int>& bit, int index) {
    int result = 0;
    while(index > 0) {
        result += bit[index];
        index -= lowbit(index);
    }
    return result;
}

void add(vector<int>& bit, int index, int val) {
    while(index < bit.size()) {
        bit[index] += val;
        index += lowbit(index);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n], result = 0;
    for(int i = 0; cin >> a[i]; i++) {
    }
    vector<int> bit(SIZE, 0);
    for(int i = n - 1; i >= 0; i--) {
        result += get(bit, a[i] - 1);
        add(bit, a[i], 1);
    }
    cout << result;
    return 0;
}
