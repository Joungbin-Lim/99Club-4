#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 1;

void dfs(vector<vector<int> > &graph, vector<int> &ord, int x) {
    for (auto y: graph[x]) {
        if (ord[y] == 0) {
            cnt += 1;
            ord[y] = cnt;
            dfs(graph, ord, y);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, r;
    int i;

    cin >> n >> m >> r;
    vector<int> ord(n + 1, 0);
    vector<vector<int> > graph(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        // 양방향 간선이므로 양쪽에 모두 저장해 줍니다.
    }
    for (i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    ord[r] = 1;
    dfs(graph, ord, r);
    for (i = 1; i <= n; ++i) {
        cout << ord[i] << "\n";
    }

    return 0;
}