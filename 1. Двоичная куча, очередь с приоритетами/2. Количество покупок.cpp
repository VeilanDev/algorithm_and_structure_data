#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int n, money; cin >> n; cin >> money;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		q.push(a);
	}

	int count = 0;
	while (money >= q.top()) {
		int item = q.top(); q.pop();
		money -= item;
		q.push(item * 2);
		count += 1;
	}
	cout << count;
}
