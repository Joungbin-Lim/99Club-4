#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

void backtrack(int fatigue, int choice, int n,
               vector<int> check, vector<vector<int> > dungeons) {
    if (choice == n) {
        answer = n;
        return;
    }

    int i;
    for (i = 0; i < n; ++i) {
        if (check[i] == 0) {
            int req, cost;
            req = dungeons[i][0];
            cost = dungeons[i][1];
            if (fatigue >= req) {
                check[i] = 1;
                backtrack(fatigue - cost, choice + 1, n, check, dungeons);
                check[i] = 0;
            }
        }
    }
    answer = max(answer, choice);
}

int solution(int k, vector<vector<int> > dungeons) {
    int n = dungeons.size();
    vector<int> check(n, 0);
    backtrack(k, 0, n, check, dungeons);
    return answer;
}
