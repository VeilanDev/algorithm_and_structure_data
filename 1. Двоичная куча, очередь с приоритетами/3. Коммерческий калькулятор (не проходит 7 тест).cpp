#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    const double kommis = 0.05;
    double money = 0.0;
    int n; cin >> n;
    priority_queue<double, vector<double>, greater<double>> numbers;
    
    for (int i = 0; i < n; i++) {
        double a; cin >> a;
        numbers.push(a);
    }
    
    while (numbers.size() > 1) {
        double num1 = numbers.top(); numbers.pop();
        double num2 = numbers.top(); numbers.pop();
        double local_sum = num1 + num2; numbers.push(local_sum);
        money += local_sum * kommis;
    }
	
    cout << money;
    return 0;
}