#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 다음 두 줄은 입력받는 속도를 빠르게 하기 위하여 작성하였습니다.
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;

    cin >> t;
    while (t--) {
        double n;
        long long ans;
        cin >> n;

        ans = (int) ((sqrt(n * 8 + 1) - 1) / 2);
        cout << ans << "\n";
    }

    return 0;
}