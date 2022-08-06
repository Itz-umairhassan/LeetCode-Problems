#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// we have to find a largest subarray with ditinct elements....
int max_array(vector<int>v) {
// 1 2 3 3 2 1 4 ..large=3..
	int large = 0;
	unordered_map<int, int>m;
	int l = 0;
	for (int i = 0;i < v.size();i++) {
		if (m.find(v[i]) != m.end()) {
			
			l = max(l, m[v[i]] + 1);
		}
		large = max(large, i - l);
		m[v[i]] = i;
	}

	return large;
}

int main() {
	vector<int>v = { 1,2,3,3,2,1,4 };
	cout << max_array(v);
	return 0;
}