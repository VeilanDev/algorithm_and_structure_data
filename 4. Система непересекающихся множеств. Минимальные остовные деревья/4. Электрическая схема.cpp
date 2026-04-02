#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    const double INF = 1e18;
    vector<double> min_dist(n, INF);
    vector<bool> used(n, false);
    
    min_dist[0] = 0;
    double total_length = 0;
    
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || min_dist[j] < min_dist[v])) {
                v = j;
            }
        }
        
        used[v] = true;
        total_length += min_dist[v];
        
        for (int to = 0; to < n; to++) {
            if (!used[to]) {
                double dx = x[v] - x[to];
                double dy = y[v] - y[to];
                double dist = sqrt(dx*dx + dy*dy);
                if (dist < min_dist[to]) {
                    min_dist[to] = dist;
                }
            }
        }
    }
    
    cout << fixed << setprecision(5) << total_length << endl;
    
    return 0;
}