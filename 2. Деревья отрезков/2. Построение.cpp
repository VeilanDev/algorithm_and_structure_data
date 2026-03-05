#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 100000;

vector<int> tree;

void build(int root, int left, int right) {
    if (left == right) {
        tree[root] = 0;
        return;
    }
    int mid = (left + right) / 2;
    build(root * 2 + 1, left, mid);
    build(root * 2 + 2, mid + 1, right);
    tree[root] = tree[root * 2 + 1] + tree[root * 2 + 2];
}

void update(int root, int left, int right, int pos, int delta) {
    if (left == right) {
        tree[root] += delta;
        return;
    }
    int mid = (left + right) / 2;
    if (pos <= mid)
        update(root * 2 + 1, left, mid, pos, delta);
    else
        update(root * 2 + 2, mid + 1, right, pos, delta);
    tree[root] = tree[root * 2 + 1] + tree[root * 2 + 2];
}

int count_greater_equal(int root, int left, int right, int qleft, int qright) {
    if (qleft > right || qright < left)
        return 0;
    if (qleft <= left && right <= qright)
        return tree[root];
    int mid = (left + right) / 2;
    return count_greater_equal(root * 2 + 1, left, mid, qleft, qright) +
           count_greater_equal(root * 2 + 2, mid + 1, right, qleft, qright);
}

int find_position(int X) {
    return count_greater_equal(0, 0, MAX_H, X, MAX_H);
}

int find_kth(int root, int left, int right, int k) {
    if (left == right)
        return left;
    
    int mid = (left + right) / 2;
    int right_count = tree[root * 2 + 2];
    
    if (k < right_count)
        return find_kth(root * 2 + 2, mid + 1, right, k);
    else
        return find_kth(root * 2 + 1, left, mid, k - right_count);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    tree.resize(4 * (MAX_H + 1));
    build(0, 0, MAX_H);
    
    for (int i = 0; i < n; i++) {
        int type, val;
        cin >> type >> val;
        
        if (type == 1) {
            int pos = find_position(val);
            cout << pos << "\n";
            update(0, 0, MAX_H, val, 1);
        } else {
            int height = find_kth(0, 0, MAX_H, val);
            update(0, 0, MAX_H, height, -1);
        }
    }
    
    return 0;
}