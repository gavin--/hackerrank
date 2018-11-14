#include <map>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(string s; cin >> s; ) {
        int result = 0;
        for(int i = 0; i != s.size(); i++) {
            for(int j = 1; i + j <= s.size(); j++) {
                map<char, int> count1;
                for(int k = i; k < i + j; k++) {
                    count1[s[k]]++;
                }
                auto count2 = count1;
                for(int k = i + 1; k + j <= s.size(); k++) {
                    auto find = count2.find(s[k - 1]);
                    if(find->second == 1) {
                        count2.erase(find);
                    } else {
                        find->second--;
                    }
                    count2[s[k + j - 1]]++;
                    if(count1 == count2) {
                        result++;
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
