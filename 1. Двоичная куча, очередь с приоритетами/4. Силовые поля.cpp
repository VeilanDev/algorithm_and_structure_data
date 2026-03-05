#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Rect {
    long long x, y;
};

bool compareByX(const Rect& a, const Rect& b) {
    return a.x > b.x;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++) {
        cin >> rects[i].x >> rects[i].y;
    }
    
    sort(rects.begin(), rects.end(), compareByX);
    
	priority_queue<long long> pq;
    long long maxArea = 0;
    
	for (int i = 0; i < k; i++) {
        pq.push(rects[i].y);
    }

    priority_queue<long long> minYHeap;
    
    for (int i = 0; i < k; i++) {
        minYHeap.push(-rects[i].y);
    }
    
    long long minX = rects[k-1].x;
    long long minY = -minYHeap.top();
    maxArea = minX * minY;
    
    for (int i = k; i < n; i++) {
        if (rects[i].y <= minY) {
            continue;
        }
        minYHeap.pop();
        minYHeap.push(-rects[i].y);
        minY = -minYHeap.top();
        minX = rects[i].x;
        
        maxArea = max(maxArea, minX * minY);
    }
    
    cout << maxArea << endl;
    return 0;
}