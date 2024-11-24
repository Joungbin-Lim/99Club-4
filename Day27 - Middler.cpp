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
    vector<int> d(n + 1, 1);
    for (i = 1; i <= n; ++i) {
        cin >> num[i];
    }

    for (i = 2; i <= n; ++i) {
        for (j = 1; j < i; ++j) {
            if (num[i] < num[j] and d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
            }
        }
    }
    for (i = 1; i <= n; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans << "\n";

    return 0;
}
