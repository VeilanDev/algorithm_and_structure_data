#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct DSU {
    vector<int> p, size;
    stack<int> changes;
    stack<int> query_types;
    
    DSU(int n) {
        p.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
    }
    
    int find(int x) {
        while (p[x] != x) {
            x = p[x];
        }
        return x;
    }
    
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            changes.push(-1);
            query_types.push(0);
            return;
        }
        
        if (size[u] > size[v]) {
            swap(u, v);
        }
        
        changes.push(u);
        query_types.push(1);
        p[u] = v;
        size[v] += size[u];
    }
    
    void rollback() {
        if (query_types.empty()) return;
        
        if (query_types.top() == 0) {
            query_types.pop();
            changes.pop();
        } else {
            int u = changes.top();
            changes.pop();
            query_types.pop();
            int v = p[u];
            p[u] = u;
            size[v] -= size[u];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u > 0 && v > 0) {
            dsu.unite(u, v);
        } else {
            dsu.rollback();
        }
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}