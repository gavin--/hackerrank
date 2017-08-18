#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int s;
    cin >> s;
    for(int n; cin >> n; ) {
        pair<int, int> intervals[n];
        for(int i = 0; i < n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        sort(intervals, intervals + n, [](pair<int, int>& left, pair<int, int>& right) {
           return left.second < right.second; 
        });
        int result = 0;
        for(int i = 0, end = 0, prev_end = 0; i < n; i++) {
            if(intervals[i].first > end) {
                end = intervals[i].second;
                result++;
            } else if(intervals[i].first > prev_end) {
                prev_end = end;
                end = intervals[i].second;
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
