#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int countSell = 0, n, money; cin >> n; cin >> money;
    vector<int> items;

    for (int i = 0; i < n; i++) {
        int item;
        cin >> item;
        items.push_back(item);
    }

    sort(items.begin(), items.end());
    while (money >= items.front()) {
        money -= items.front();
        items.front() *= 2;
        countSell += 1;
        sort(items.begin(), items.end());
    }
    cout << countSell;
    
    return 0;
}