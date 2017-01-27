#include <map>
#include <iostream>
using namespace std;

int main() {
    map<int, int> a;
    int N, count = 0;
    cin >> N;
    for(int i; cin >> i; ) {
        a[i]++;
    }
    for(auto& i : a) {
        cout << N - count << endl;
        count += i.second;
    }
    return 0;
}
