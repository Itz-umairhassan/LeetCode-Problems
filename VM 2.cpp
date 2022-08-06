#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
// Virual Machine allocation problem from senior coding competition.....
int main() {

	int test;cin >> test;
	while (test--) {

		unordered_map<double, pair<int, int>>map;
		priority_queue<double, vector<double>, greater<double>>p;
		pair<int, int>m;
		int a, b;
		cin >> a >> b;
		m = { a,b };
		double ans;
		int t;cin >> t;
		while (t--) {
			cin >> a >> b;
			ans = double(a) / double(m.first) + double(b) / double(m.second);
			p.push(ans);
			map[ans] = { a,b };
		}

		double top;
		int count = 0;
		while (!p.empty()) {
			top = p.top();
			m.first -= map[top].first;
			m.second -= map[top].second;
			if (m.first < 0 || m.second < 0)
				break;           // we have reaced at the end...
			count++;
			p.pop();
		}
		cout << count;
	}
}