#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }

    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges; // вес, u, v

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;
    int edges_used = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            total_cost += w;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }

    if (edges_used == n - 1) {
        cout << total_cost << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}