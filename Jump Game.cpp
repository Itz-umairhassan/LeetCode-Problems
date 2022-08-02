#include<iostream>
#include<vector>
using namespace std;
bool jump_possible(vector<int>arr,int size) {
	if (size <= 1)  //already at the end..so no need to jump
		return true;
	int jump = 0;
	pair<int, int>interval {0, 0};
	int reach;
	while (1) {
		reach = -1;
		for (int i = interval.second;i >= interval.first;i--)
			reach = max(reach, i+arr[i]);
		if (reach >= size - 1)
			return true;      // ball has reached at the last end...
		interval = make_pair(interval.second + 1, reach); // make new interval...
		if (interval.first > interval.second)
			return false;
	}
	_ASSERT(false);  
}

bool check(vector<int>n) {
	int size = n.size();
	int reach = 0;
	for (int i = 0;i <= reach;i++) {
		reach = max(reach, i+n[i]);
		if (reach >= size - 1)
			return true;
	}
	return false;
}
int main() {// 1 2 3 0 0 2
	vector<int>v;
	int val;
	while (cin >> val) {
		v.push_back(val);
		if (cin.get() == '\n')
			break;
	}
	//cout << jump_possible(v, v.size());
	cout << check(v);
	return 0;
}