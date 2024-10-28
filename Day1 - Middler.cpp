#include <iostream>

using namespace std;

int main() {
    long long x, y, ans;

    cin >> x >> y;
    long long z = (y * 100) / x;
    long long comp1 = (z + 1) * x - 100 * y, comp2 = 100 - (z + 1);

    if(z >= 99) ans = -1;
    else {
        ans = comp1 / comp2;
        if(comp1 % comp2 != 0) ans += 1;
    }

    cout << ans << "\n";

    return 0;
}
