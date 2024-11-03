#include <vector>
#include <climits>

using namespace std;

long long solution(int n, vector<int> times) {
    const long long MAXNUM = LONG_LONG_MAX / times.size();
    long long l = 0, r = MAXNUM, mid = 0, people, answer;
    while (l <= r) {
        people = 0;
        mid = (l + r) / 2;
        for(auto x : times) {
            people += (mid / x);
        }

        if(people < n) l = mid + 1;
        else {
            // 최소 n명을 심사할 수 있다면, 일단 해당 값을 답으로 저장하고
            // 이보다 더 작은 값을 찾습니다.
            answer = mid;
            r = mid - 1;
        }
    }

    return answer;
}