#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int n, m;
vector<pair<int,int>> g[N]; // {to, weight}
int dist[N];
bool vis[N];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // 如果是无向图：
        // g[v].push_back({u, w});
    }

    int s = 1; // 起点
    dijkstra(s);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }

    return 0;
}