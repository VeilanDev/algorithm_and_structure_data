#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long sum;
    long long assign;
    bool has_assign;
};

vector<int> a;
vector<Node> tree;

void build(int root, int left, int right) {
    if (left == right) {
        tree[root].sum = a[left];
        tree[root].has_assign = false;
        return;
    }
    
    int mid = (left + right) / 2;
    build(root * 2 + 1, left, mid);
    build(root * 2 + 2, mid + 1, right);
    
    tree[root].sum = tree[root * 2 + 1].sum + tree[root * 2 + 2].sum;
    tree[root].has_assign = false;
}

void push(int root, int left, int right) {
    if (tree[root].has_assign) {
        long long val = tree[root].assign;
        int mid = (left + right) / 2;
        
        tree[root * 2 + 1].assign = val;
        tree[root * 2 + 1].has_assign = true;
        tree[root * 2 + 1].sum = val * (mid - left + 1);
        
        tree[root * 2 + 2].assign = val;
        tree[root * 2 + 2].has_assign = true;
        tree[root * 2 + 2].sum = val * (right - mid);
        
        tree[root].has_assign = false;
    }
}

void assign(int root, int left, int right, int qleft, int qright, long long val) {
    if (qleft <= left && right <= qright) {
        tree[root].assign = val;
        tree[root].has_assign = true;
        tree[root].sum = val * (right - left + 1);
        return;
    }
    
    if (qleft > right || qright < left) {
        return;
    }
    
    push(root, left, right);
    
    int mid = (left + right) / 2;
    assign(root * 2 + 1, left, mid, qleft, qright, val);
    assign(root * 2 + 2, mid + 1, right, qleft, qright, val);
    
    tree[root].sum = tree[root * 2 + 1].sum + tree[root * 2 + 2].sum;
}

long long query(int root, int left, int right, int qleft, int qright) {
    if (qleft <= left && right <= qright) {
        return tree[root].sum;
    }
    
    if (qleft > right || qright < left) {
        return 0;
    }
    
    push(root, left, right);
    
    int mid = (left + right) / 2;
    return query(root * 2 + 1, left, mid, qleft, qright) +
           query(root * 2 + 2, mid + 1, right, qleft, qright);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    tree.resize(4 * n);
    build(0, 0, n - 1);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--; r--; 
            
            long long result = query(0, 0, n - 1, l, r);
            cout << result << "\n";
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            l--; r--;
            
            assign(0, 0, n - 1, l, r, v);
        }
    }
    
    return 0;
}