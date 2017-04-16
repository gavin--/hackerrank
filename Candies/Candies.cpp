#include <iostream>
using namespace std;

int main() {
    long long N, result = 1, descending = 0, last, peak = 1;
    cin >> N >> last;
    for(long long rating; cin >> rating; last = rating) {
        if(rating >= last) {
            if(descending > 0) {
                result += descending * (descending + 1) / 2;
                if(descending >= peak) {
                    result += descending - peak + 1;
                }
                peak = 1;
                descending = 0;
            }
            if(rating > last) {
                peak = peak + 1;
            } else {
                peak = 1;
            }
            result += peak;
        } else {
            descending++;
        }
    }
    if(descending > 0) {
        result += descending * (descending + 1) / 2;
        if(descending >= peak) {
            result += descending - peak + 1;
        }
    }
    cout << result;
    return 0;
}
