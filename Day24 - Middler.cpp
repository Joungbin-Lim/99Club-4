#include <vector>
#include <algorithm>

using namespace std;

void dfs(int cur, int prev, vector<vector<int> > graph, vector<int> &subtree) {
    for (auto nxt: graph[cur]) {
        if (nxt == prev) continue;
        dfs(nxt, cur, graph, subtree);
        subtree[cur] += subtree[nxt];
    }
}

using namespace std;

int solution(int n, vector<vector<int> > wires) {
    int i, j;
    int x, y;
    int res;

    int answer = n;
    vector<vector<int> > graph(n + 1);
    vector<int> subtree(n + 1, 1);

    for (i = 0; i < n - 1; ++i) {
        x = wires[i][0];
        y = wires[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, -1, graph, subtree);
    for (i = 1; i <= n; ++i) {
        res = abs(2 * subtree[i] - n);
        answer = min(answer, res);
    }

    return answer;
}