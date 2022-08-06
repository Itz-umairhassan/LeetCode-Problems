#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_profit(vector<pair<int, int>>v, int capacity) {
	int profit = 0;
	for (auto i : v) {
		if (capacity >= i.second) {
			capacity -= i.second;
			profit += i.first;
		}
		else {
			double value_per_unit = double(i.first) / double(i.second);
			profit += (capacity * value_per_unit);
			break;
		}
	}
	return profit;
}

int main() {
	int cap;cin >> cap;
	int n;cin >> n;
	int w, v;
	vector<pair<int, int>>vec;
	while(n--) {
		cin >> v >> w;
		vec.push_back({ v,w });
	}

	sort(vec.begin(), vec.end(), [&](pair<int, int>&temp1,pair<int,int>&temp2) {
		// sort on the basis of weight/value ratio
		double v1 = double(temp1.first) / double(temp1.second);
		double v2 = double(temp2.first) / double(temp2.second);
		return v1 > v2;
		});

	cout << "Max Profit: " << max_profit(vec, cap);
	return 0;
}