#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i; cin >> i; ){
       sum += i;
    }
    cout << sum;
    return 0;
}
