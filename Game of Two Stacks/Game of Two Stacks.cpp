#include <iostream>
using namespace std;

int main() {
    int g;
    cin >> g;
    for(int n, m, x; cin >> n >> m >> x; ) {
        int a[n], b[m];
        for(auto i = 0; i != n; i++) {
            cin >> a[i];
        }
        for(auto i = 0; i != m; i++) {
            cin >> b[i];
        }
        auto i = 0;
        auto sum = 0ll;
        while(i != n && sum + a[i] <= x) {
            sum += a[i];
            i++;
        }
        auto result = i;
        for(auto j = 0; j < m; j++) {
            sum += b[j];
            while(sum > x && i > 0) {
                i--;
                sum -= a[i];
            }
            if(sum <= x && i + j >= result) {
                result = i + j + 1;
            }   
        }
        cout << result << endl;
    }
    return 0;
}
