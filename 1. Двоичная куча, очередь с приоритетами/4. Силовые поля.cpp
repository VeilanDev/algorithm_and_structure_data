#include <queue>
#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

struct PointsLess {
	bool operator () (const Point& p1, const Point& p2) {
		return p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y;
	}
};

int main() {
	int n, count; cin >> n; cin >> count;
	priority_queue<Point, vector<Point>, PointsLess> rect;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x; cin >> y;
		rect.push({x, y});
	}

	while (rect.size() > 0) {
		Point xy = rect.top(); rect.pop();
		cout << xy.x << "," << xy.y << " ";
	}
}
