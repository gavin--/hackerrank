#include <iostream>
#include <set>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    set<char> set(b.begin(), b.end());
    int** dpprefix = new int*[a.size() + 1], **dpsuffix = new int*[a.size() + 1];
    dpprefix[0] = new int[b.size() + 1]();
    dpsuffix[0] = new int[b.size() + 1]();
    for(auto i = 1; i <= a.size(); i++) {
        dpprefix[i] = new int[b.size() + 1];
        dpsuffix[i] = new int[b.size() + 1];
        dpprefix[i][0] = 0;
        dpsuffix[i][0] = 0;
        for(auto j = 1; j <= b.size(); j++) {
            if(a[i - 1] == b[j - 1]) {
                dpprefix[i][j] = dpprefix[i - 1][j - 1] + 1;
            } else {
                dpprefix[i][j] = max(dpprefix[i][j - 1], dpprefix[i - 1][j]);
            }
            if(a.rbegin()[i - 1] == b.rbegin()[j - 1]) {
                dpsuffix[i][j] = dpsuffix[i - 1][j - 1] + 1;
            } else {
                dpsuffix[i][j] = max(dpsuffix[i][j - 1], dpsuffix[i - 1][j]);
            }
        }
    }
    auto result = 0, lcs = dpprefix[a.size()][b.size()];
    for(auto i = 0; i <= a.size(); i++) {
        for(auto c : set) {
            for(auto j = 0; j < b.size(); j++) {
                if(b[j] == c && dpprefix[i][j] + dpsuffix[a.size() - i][b.size() - j - 1] == lcs) {
                    result++;
                    break;
                }
            }
        }
    }
    cout << result;
    return 0;
}
