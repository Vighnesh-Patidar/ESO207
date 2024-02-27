#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];

int main() {

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i > 1) {
			adj[x].push_back(i);
			adj[i].push_back(x);
		}
	}

	int nf; cin >> nf;
	vector<int> vf(nf);
	for (auto & i : vf)
		cin >> i;
	sort(vf.begin(), vf.end());

	vector<int> res(n + 1, -1);
	queue<int> q;
	for (auto & i : vf) {
		q.push(i);
		res[i] = i;
	}

	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto & v : adj[u]) {
			if (res[v] == -1) {
				res[v] = res[u];
				q.push(v);
			}
		}
	}

	int qr; cin >> qr;
	for (int i = 0; i < qr; i++) {
		int x; cin >> x;
		cout << res[x];
        if(i != qr - 1) cout << endl;
        
	}

	return 0;
}