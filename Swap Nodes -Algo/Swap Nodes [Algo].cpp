#include <iostream>
#include <array>
using namespace std;

void swap(array<int, 2>* tree, int root, int K, int level) {
    if(root == -2) {
        return;
    }
    if(level % K == 0) {
        swap(tree[root][0], tree[root][1]);
    }
    swap(tree, tree[root][0], K, level + 1);
    cout << root + 1 << ' ';
    swap(tree, tree[root][1], K, level + 1);
}

int main() {
    int n, T;
    cin >> n;
    array<int, 2> tree[n];
    for(auto i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        left--;
        right--;
        tree[i][0] = left;
        tree[i][1] = right;
    }
    cin >> T;
    for(int K; cin >> K; cout << endl) {
        swap(tree, 0, K, 1);
    }
    return 0;
}
