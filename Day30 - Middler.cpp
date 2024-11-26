#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int i, j;
    int ans = 0;

    cin >> n;
    vector<int> box(n + 1, 0);
    vector<int> max_box(n + 1, 1);
    for (i = 1; i <= n; ++i) {
        cin >> box[i];
    }
    for (i = 2; i <= n; ++i) {
        for (j = 1; j < i; ++j) {
            if (box[i] > box[j] and max_box[i] < max_box[j] + 1) {
                max_box[i] = max_box[j] + 1;
            }
        }
    }
    for (i = 1; i <= n; ++i) {
        ans = max(ans, max_box[i]);
    }
    cout << ans << "\n";

    return 0;
}