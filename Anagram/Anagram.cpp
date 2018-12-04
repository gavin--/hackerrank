#include <map>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        int result = 0;
        if(s.size() % 2 == 1) {
            result = -1;
        } else {
            map<char, int> count;
            for(int i = 0; i != s.size() / 2; i++) {
                count[s[i]]++;
            }
            for(int i = s.size() / 2; i != s.size(); i++) {
                auto find = count.find(s[i]);
                if(find == count.end() || find->second <= 0) {
                    result++;
                } else {
                    find->second--;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
