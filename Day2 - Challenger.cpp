#include <iostream>
#include <vector>

const int MAXNUM = 1 << 20;

using namespace std;

int main() {
    int n, m;
    int a, b, x;
    int bacon_sum, min_sum = MAXNUM, ans = 0;

    cin >> n >> m;
    vector<vector<int> > matrix(n + 1, vector<int>(n + 1, MAXNUM));
    vector<int> bacon(n + 1, 0);
    for (a = 1; a <= n; ++a) {
        matrix[a][a] = 0;
    }
    while (m--) {
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    for (x = 1; x <= n; ++x) {
        for (a = 1; a <= n; ++a) {
            for (b = 1; b <= n; ++b) {
                if (matrix[a][b] > matrix[a][x] + matrix[x][b]) {
                    matrix[a][b] = matrix[a][x] + matrix[x][b];
                }
            }
        }
    }

    for (a = 1; a <= n; ++a) {
        bacon_sum = 0;
        for (b = 1; b <= n; ++b) {
            if (matrix[a][b] != MAXNUM) {
                bacon_sum += matrix[a][b];
            }
        }
        bacon[a] = bacon_sum;
    }
    for (a = 1; a <= n; ++a) {
        if (bacon[a] < min_sum) {
            ans = a;
            min_sum = bacon[a];
        }
    }
    cout << ans << "\n";
    return 0;
}