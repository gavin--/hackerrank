#include <iostream>
#include <vector>
using namespace std;

int lowbit(int i) {
    return i & -i;
}

void add(vector<int>& bit, int index, int increment) {
    while(index > 0) {
        bit[index] = bit[index] + increment;
        index -= lowbit(index);
    }
}

int sum(vector<int>& bit, int index) {
    int sum = 0;
    while(index < bit.size()) {
        sum = sum + bit[index];
        index += lowbit(index);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int a[n], result = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> bit(n + 1);
        for(int i = 0; i < n; i++) {
            if(a[i] - i > 3) {
                result = -1;
                break;
            }
            result += sum(bit, a[i]);
            add(bit, a[i], 1);
        }
        if(result == -1) {
            cout << "Too chaotic\n";
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
