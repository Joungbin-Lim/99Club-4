#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int i, j;
    int ans = 0;
    cin >> n;

    vector<int> num(n + 1);
    vector<int> d(n + 1, 0);
    for (i = 1; i <= n; ++i) {
        cin >> num[i];
        d[i] = num[i];
    }

    for (i = 2; i <= n; ++i) {
        for (j = 1; j < i; ++j) {
            if (num[i] > num[j] && d[i] < d[j] + num[i]) {
                d[i] = d[j] + num[i];
            }
        }
    }
    for (i = 1; i <= n; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans << "\n";

    return 0;
}