#include <iostream>

using namespace std;


int main(){
    int T;
    for(cin >> T; T > 0; T--){
        int N;
        cin >> N;
        cout << N * (N - 1) / 2 << endl;
    }
    return 0;
}
