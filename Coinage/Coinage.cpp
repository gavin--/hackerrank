#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int N, A, B, C, D; cin >> N >> A >> B >> C >> D; ) {
        auto result = 0ll;
        for(auto b = 0; b <= min(B, N / 2); b++) {
            auto rb = N - 2 * b;
            for(auto c = 0; c <= C; c++) {
                auto rc = rb - 5 * c;
                if(rc < 0) {
                    break;
                }
                for(auto d = 0; d <= D; d++) {
                    auto a = rc - 10 * d;
                    if(a < 0) {
                        break;
                    }
                    if(a > A) {
                        continue;
                    }
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
