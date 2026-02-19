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
	priority_queue<Point, vector<Point>, PointsLess> rect1;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x; cin >> y;
		rect1.push({x, y});
	}
	priority_queue<Point, vector<Point>, PointsLess> rect2 = rect1;

	Point xy1 = rect1.top(); rect1.pop();
	Point xy2 = rect2.top(); rect2.pop();

	int s = xy1.x * xy2.y;
	cout << s;

}
