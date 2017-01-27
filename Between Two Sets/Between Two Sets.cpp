#include <list>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m], largest = 0;
    for(auto i = 0; i != n; i++) {
        cin >> a[i];
    }
    for(auto i = 0; cin >> b[i]; i++) {
        largest = max(largest, b[i]);
    }
    list<int> between;
    for(auto i = 1; i <= largest; i++) {
        bool factor = true;
        for(auto j = 0; j != m; j++) {
            if(b[j] % i != 0) {
                factor = false;
            }
        }
        if(factor) {
            between.emplace_back(i);
        }
    }
    for(auto it = begin(between); it != end(between); ) {
        bool factor = true;
        for(auto j = 0; j != n; j++) {
            if(*it % a[j] != 0) {
                factor = false;
            }
        }
        if(!factor) {
            it = between.erase(it);
        } else {
            it++;
        }
    }
    cout << between.size();
    return 0;
}
