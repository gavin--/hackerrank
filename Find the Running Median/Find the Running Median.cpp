#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> min, max;
    for(int a; cin >> a; ) {
        if(min.size() == max.size()) {
            if(max.empty() || max[0] < a) {
                min.emplace_back(a);
                push_heap(begin(min), end(min), greater<int>());
            } else {
                max.emplace_back(a);
                push_heap(begin(max), end(max));
            }
        } else if(min.size() < max.size()) {
            if(max[0] < a) {
                min.emplace_back(a);
                push_heap(begin(min), end(min), greater<int>());
            } else {
                min.emplace_back(max[0]);
                push_heap(begin(min), end(min), greater<int>());
                pop_heap(begin(max), end(max));
                max[max.size() - 1] = a;
                push_heap(begin(max), end(max));
            }
        } else {
            if(min[0] > a) {
                max.emplace_back(a);
                push_heap(begin(max), end(max));
            } else {
                max.emplace_back(min[0]);
                push_heap(begin(max), end(max));
                pop_heap(begin(min), end(min), greater<int>());
                min[min.size() - 1] = a;
                push_heap(begin(min), end(min), greater<int>());
            }
        }
        if(min.size() == max.size()) {
            cout << (max[0] + min[0]) / 2;
            if((max[0] + min[0]) % 2 == 1) {
                cout << ".5\n";
            } else {
                cout << ".0\n";
            }
        } else {
            if(min.size() < max.size()) {
                cout << max[0] << ".0\n";
            } else {
                cout << min[0] << ".0\n";
            }
        }
    }
    return 0;
}
