#include <iostream>
using namespace std;

long long sqrt(long long n) {
    auto begin = 1ll, end = n;
    while(begin < end) {
        auto mid = (end + begin + 1) / 2;
        if(mid <= n / mid) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

int main() {
    int q;
    cin >> q;
    for(long long a, b, c, d; cin >> a >> b >> c >> d; ) {
        auto result = 0;
        auto a2 = a * a;
        for(auto y = 1ll; y <= d; y++) {
            auto discriminant = a2 - 4 * (y * y - b * y);
            if(discriminant > 0) {
                auto root = sqrt(discriminant);
                if(root * root == discriminant) {
                    auto x1 = a + root;
                    auto x2 = a - root;
                    if(x1 % 2 == 0 && x1 / 2 >= 1 && x1 / 2 <= c) {
                        result++;
                    }
                    if(x2 % 2 == 0 && x2 / 2 >= 1 && x2 / 2 <= c) {
                        result++;
                    }
                }
            } else if(discriminant == 0) {
                if(a % 2 == 0 && a >= 2 && a / 2 <= c) {
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
