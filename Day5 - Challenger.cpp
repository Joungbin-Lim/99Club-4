#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool CompareDates(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
// 날짜를 비교하는 함수입니다. 피는 날짜를 우선으로 하며,
// 만일 피는 날짜가 같다면 지는 날짜가 더 늦은 꽃이 우선순위가 됩니다.

int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    int i;
    int ans = 0;

    cin >> n;
    vector<int> day_sum(13, 0);
    // 누적 일수를 저장하는 배열입니다.
    vector<pair<int, int> > dates;
    for (i = 1; i <= 12; ++i) {
        day_sum[i] = day_sum[i - 1] + month_days[i];
    }
    // day_sum[x]는 x월까지의 누적 일수가 됩니다.

    while (n--) {
        int st_month, st_day, end_month, end_day;
        int st_date, end_date;
        cin >> st_month >> st_day >> end_month >> end_day;
        st_date = day_sum[st_month - 1] + st_day;
        end_date = day_sum[end_month - 1] + end_day;
        if (st_date < 60) {
            if (end_date < 60) continue;
            st_date = 60;
        }
        if (end_date > 335) {
            if (st_date > 335) continue;
            end_date = 335;
        }
        pair<int, int> p = make_pair(st_date, end_date);
        dates.push_back(p);
    }
    sort(dates.begin(), dates.end(), CompareDates);

    int next_date = dates[0].second;
    int next_max = next_date;
    int ord = 1;
    if (dates[0].first == 60) {
        // 첫 번째 꽃이 3월 1일 혹은 그 이전에 핀다면
        ans = 1;
        while (next_date < 335) {
            ans += 1;
            while (ord < dates.size() and dates[ord].first <= next_date) {
            // 다음에 확인할 꽃이 피는 날짜가 현재 기준 가장 늦게 지는 꽃의 날짜보다 앞서거나 같은 날이면
                if (next_max < dates[ord].second) next_max = dates[ord].second;
                ord += 1;
                // 해당 꽃이 지는 날짜를 확인한 후 순서를 업데이트합니다.
            }
            next_date = next_max;
            // 가장 늦게 지는 꽃에 대한 날짜를 저장합니다.
            if((ord >= dates.size() and next_date < 335) or
                // 만일 모든 꽃이 11월 30일 혹은 그 이전에 지거나
                (ord < dates.size() and dates[ord].first > next_date)) {
                // 꽃이 지고 나서 다른 꽃이 피기까지의 공백기가 생긴다면
                ans = 0;
                break;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}