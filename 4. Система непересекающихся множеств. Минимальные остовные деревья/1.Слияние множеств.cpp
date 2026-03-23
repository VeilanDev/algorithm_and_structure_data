#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
	vector<int> p, s;
	
	DSU(int n) {
		p.resize(n + 1);
		s.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) {
			p[i] = i;
		}
	}
	
	int get_root(int u) {
		while (p[u] != u) {
			u = p[u];
		}
		return u;
	}
	
	bool in_one_set(int u, int v) {
		return get_root(u) == get_root(v);
	}
	
	bool make_union(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v) {
			return false;
		}
		if (s[u] > s[v]) {
			swap(u, v);
		}
		s[v] += s[u];
		p[u] = v;
		return true;
	}
};

int main() {
	int n, m;
	cin >> n; cin >> m;
	DSU dsu(n);
	
	int i = 0;
	while (i < m) {
		int u, v; cin >> u; cin >> v;
		dsu.make_union(u, v);
		i++;
	}
	
	/*for (int i = 1; i <= n; i++) {
		cout << i;
	} cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << dsu.p[i];
	} cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << dsu.s[i];
	} cout << "\n";*/
	
	int count = 0;
	vector<int> p_2;
	for (int i = 0; i <= n; i++) {
		p_2.push_back(dsu.get_root(i));
	}
	sort(p_2.begin(), p_2.end());

	for (int i = 1; i <= n; i++) {
		int root = p_2[i - 1];
		if (root == p_2[i])
			continue;
		count++;
		//cout << dsu.get_root(i);
	}

	cout << count;
	return 0;
}
