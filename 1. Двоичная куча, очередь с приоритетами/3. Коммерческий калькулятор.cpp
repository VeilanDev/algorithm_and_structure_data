#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	float kommis = 0.05, money = 0.0;
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> numbers;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		numbers.push(a);
	}

	while (numbers.size() > 1) {
		int num1 = numbers.top(); numbers.pop();
		int num2 = numbers.top(); numbers.pop();
		float local_sum = num1 + num2; numbers.push(local_sum);
		money += local_sum * kommis;
		//cout << num1 << " + " << num2 << " = " << local_sum << " : " << money << " : " << local_sum * kommis << "\n";		
	}
	cout << money;
	
}
