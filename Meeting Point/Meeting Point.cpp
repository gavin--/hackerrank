#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    cin >> N;
    array<pair<long long, long long>, 2> points[N];
    for(long long i = 0; cin >> points[i][0].first >> points[i][0].second; i++) {
        points[i][0] = {points[i][0].first + points[i][0].second, points[i][0].second - points[i][0].first};
    }
    sort(points, points + N, [](array<pair<long long, long long>, 2>& left, array<pair<long long, long long>, 2>& right) {
        return left[0].first < right[0].first;
    });
    for(long long i = 1; i < N; i++) {
        points[0][1].first += abs(points[i][0].first - points[0][0].first);
    }
    for(long long i = 1; i < N; i++) {
        long long t = abs(points[i][0].first - points[i - 1][0].first);
        points[i][1].first = points[i - 1][1].first + t * i - t * (N - i);
    }
    sort(points, points + N, [](array<pair<long long, long long>, 2>& left, array<pair<long long, long long>, 2>& right) {
        return left[0].second < right[0].second;
    });
    for(long long i = 1; i < N; i++) {
        points[0][1].second += abs(points[i][0].second - points[0][0].second);
    }
    for(long long i = 1; i < N; i++) {
        long long t = abs(points[i][0].second - points[i - 1][0].second);
        points[i][1].second = points[i - 1][1].second + t * i - t * (N - i);
    }
    long long result = points[0][1].first + points[0][1].second;
    for(long long i = 1; i < N; i++) {
        result = min(result, points[i][1].first + points[i][1].second);
    }
    cout << result / 2;
    return 0;
}
