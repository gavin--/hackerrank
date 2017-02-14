#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> set;
    int Q;
    cin >> Q;
    for(int type; cin >> type; ) {
        switch(type) {
            case 1:
                int v;
                cin >> v;
                set.emplace(v);
                break;
            case 2:
                cin >> v;
                set.erase(v);
                break;
            case 3:
                cout << *set.begin() << endl;
        }
    }
    return 0;
}
