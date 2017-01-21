#include <iostream>
using namespace std;


int main() {
    int n;
    for(cin >> n; n > 0; n--) {
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        cout << qx + qx - px << ' ' << qy + qy - py << endl;
    }
    return 0;
}
