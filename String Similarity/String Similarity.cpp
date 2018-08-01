#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(string s; cin >> s; ) {
        int n = s.size(), inverse[n], temp[n], sa[n];
        if(n == 1) {
            cout << "1\n";
            continue;
        }
        temp[0] = 0;
        temp[n - 1] = n;
        for(int i = 0; i < n; i++) {
            sa[i] = i;
            inverse[i] = s[i];
        }
        for(int gap = 1; temp[n - 1] != n - 1; gap *= 2) {
            auto cmp = [&gap, &inverse, &n](int i, int j) {
                if(inverse[i] != inverse[j]) {
                    return inverse[i] < inverse[j];
                }
                if(i + gap < n && j + gap < n) {
                    return inverse[i + gap] < inverse[j + gap];
                }
                return i > j;
            };
            sort(sa, sa + n, cmp);
            for(int i = 0; i < n - 1; i++) {
                temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
            }
            for(int i = 0; i < n; i++) {
                inverse[sa[i]] = temp[i];
            }
        }
        int* lcp = temp;
        for(int i = 0, k = 0; i < n; i++) {
            if(inverse[i] == n - 1) {
                k = 0;
                continue;
            }
            for(int j = sa[inverse[i] + 1]; s[i + k] == s[j + k]; k++) {
            }
            lcp[inverse[i]] = k;
            if(k > 0) {
                k--;
            }
        }
        long long result = n;
        for(int i = inverse[0], j = n; i > 0; i--) {
            j = min(j, lcp[i - 1]);
            result += j;
        }
        for(int i = inverse[0] + 1, j = n; i < n; i++) {
            j = min(j, lcp[i - 1]);
            result += j;
        }
        cout << result << endl;
    }
    return 0;
}
