#include <map>
#include <iostream>
using namespace std;

int main() {
    map<string, int> count;
    int N, Q;
    for(cin >> N; N > 0; N--) {
        string s;
        cin >> s;
        count[s]++;
    }
    cin >> Q;
    for(string s; cin >> s; ) {
        auto find = count.find(s);
        if(find == count.end()) {
            cout << 0;
        } else {
            cout << find->second;
        }
        cout << endl;
    }
    return 0;
}
