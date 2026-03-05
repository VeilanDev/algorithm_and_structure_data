#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x * 100);
    }
    
    long long totalCommission = 0;
    
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        
        long long sum = a + b;
        long long commission = (sum * 5) / 100;
        
        totalCommission += commission; pq.push(sum);
    }
    
    cout << totalCommission / 100 << "." 
         << setw(2) << setfill('0') << totalCommission % 100 << endl;
    
    return 0;
}