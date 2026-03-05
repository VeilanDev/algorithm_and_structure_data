#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int min_seats;
    int add;
};

vector<Node> tree;
int GLOBAL_K;

void build(int root, int left, int right) {
    tree[root].add = 0;
    if (left == right) {
        tree[root].min_seats = GLOBAL_K;
        return;
    }
    int mid = (left + right) / 2;
    build(root * 2 + 1, left, mid);
    build(root * 2 + 2, mid + 1, right);
    tree[root].min_seats = min(tree[root * 2 + 1].min_seats, 
                               tree[root * 2 + 2].min_seats);
}

void push(int root) {
    if (tree[root].add != 0) {
        tree[root * 2 + 1].add += tree[root].add;
        tree[root * 2 + 2].add += tree[root].add;
        tree[root * 2 + 1].min_seats += tree[root].add;
        tree[root * 2 + 2].min_seats += tree[root].add;
        tree[root].add = 0;
    }
}

void update(int root, int left, int right, int qleft, int qright) {
    if (qleft > right || qright < left) return;
    
    if (qleft <= left && right <= qright) {
        tree[root].add -= 1;
        tree[root].min_seats -= 1;
        return;
    }
    
    push(root);
    int mid = (left + right) / 2;
    update(root * 2 + 1, left, mid, qleft, qright);
    update(root * 2 + 2, mid + 1, right, qleft, qright);
    tree[root].min_seats = min(tree[root * 2 + 1].min_seats, 
                               tree[root * 2 + 2].min_seats);
}

int query_min(int root, int left, int right, int qleft, int qright) {
    if (qleft > right || qright < left) return GLOBAL_K + 1;
    
    if (qleft <= left && right <= qright) {
        return tree[root].min_seats;
    }
    
    push(root);
    int mid = (left + right) / 2;
    return min(query_min(root * 2 + 1, left, mid, qleft, qright),
               query_min(root * 2 + 2, mid + 1, right, qleft, qright));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, M;
    cin >> N >> K >> M;
    GLOBAL_K = K;
    
    tree.resize(4 * (N - 1));
    build(0, 0, N - 2);
    
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        
        int min_seats = query_min(0, 0, N - 2, X, Y - 1);
        
        if (min_seats > 0) {
            cout << "Yes\n";
            update(0, 0, N - 2, X, Y - 1);
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}