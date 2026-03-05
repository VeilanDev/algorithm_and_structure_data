#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> t;

void build(int root, int left, int right) {
    if (left == right) {
        t[root] = a[left];
        return;
    }
    
    int mid = (left + right) / 2;
    build(2 * root + 1, left, mid);
    build(2 * root + 2, mid + 1, right);
    
    t[root] = min(t[2 * root + 1], t[2 * root + 2]);
}

int query(int root, int left, int right, int qleft, int qright) {
    if (left >= qleft && right <= qright) {
        return t[root];
    }

    if (qleft > right || qright < left) {
        return INT_MAX;
    }
    
    int mid = (left + right) / 2;
    int left_min = query(2 * root + 1, left, mid, qleft, qright);
    int right_min = query(2 * root + 2, mid + 1, right, qleft, qright);
    
    return min(left_min, right_min);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    t.resize(4 * n);
    build(0, 0, n - 1);
    
    int m; cin >> m;
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        int result = query(0, 0, n - 1, l, r);
        cout << result << "\n";
    }
    
    return 0;
}