#include <iostream>
using namespace std;

int main() {
    int n, min, max, best = 0, worst = 0;
    cin >> n >> min;
    max = min;
    for(int s; cin >> s; ) {
        if(s < min) {
            min = s;
            worst++;
        }
        if(s > max) {
            max = s;
            best++;
        }
    }
    cout << best << ' ' << worst;
    return 0;
}
