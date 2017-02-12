#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int N;
    for(cin >> N; N > 0; N--) {
        int A, B, C;
        cin >> A >> B >> C;
        if(A > B) {
            swap(A, B);
        }
        auto bottom = 2 * A * B, top = 1;
        if(C >= A + B) {
            bottom = 1;
        } else if(C <= A) {
            top = C * C;
        } else if(A < C && C <= B) {
            top = 2 * A * (C - A) + A * A;
        } else {
            top = 2 * A * (C - A) + 2 * (A + B - C) * (C - B) + (A + B - C) * (A + B - C);
        }
        auto g = gcd(top, bottom);
        cout << top / g << '/' << bottom / g << endl;
    }
    return 0;
}
