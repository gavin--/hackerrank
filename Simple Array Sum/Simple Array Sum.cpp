#include <iostream>
#include <numeric>
#include <iterator>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << accumulate(istream_iterator<int>(cin), istream_iterator<int>(), 0);
    return 0;
}
