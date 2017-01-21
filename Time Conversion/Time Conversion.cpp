#include <iostream>
using namespace std;

int main(){
    string time;
    cin >> time;
    if(time[8] == 'P' && !(time[0] == '1' && time[1] == '2')) {
        time[0]++;
        time[1] += 2;
    }
    if(time[0] == '1' && time[1] == '2' && time[8] == 'A') {
        time[0] = '0';
        time[1] = '0';
    }
    cout << time.substr(0, 8);
    return 0;
}
