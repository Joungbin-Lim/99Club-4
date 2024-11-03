#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define ll long long

int main() {
    int n, m;
    int ans = 0;

    cin >> n >> m;
    vector<int> tree;
    while (n--) {
        int height;
        cin >> height;
        tree.push_back(height);
    }

    ll l = 0, r = LONG_LONG_MAX, mid = 0;
    while (l <= r) {
        ll take_away = 0;
        mid = (l + r) / 2;
        for (auto x: tree) {
            if (x > mid) take_away += (x - mid);
        }
        if (take_away >= m) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << "\n";

    return 0;
}