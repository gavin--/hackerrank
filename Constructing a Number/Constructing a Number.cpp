#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int n; cin >> n; ) {
        int sum = 0;
        for(string s; n > 0; n--) {
            cin >> s;
            for(auto i : s) {
                sum += i - '0';
            }
        }
        if(sum % 3 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
	return 0;
}
