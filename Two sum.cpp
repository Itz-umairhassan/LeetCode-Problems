//#include<iostream>
//#include<vector>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//vector<int>twosum(vector<int>v, int val) {
//	unordered_map<int, int>m;
//	vector<int>ans;
//	m[v[0]] = 0;
//	int res = 0;
//	for (int i = 1;i < v.size();i++) {
//		res = val - v[i];
//		if (m.find(res) != m.end()) {
//			ans.push_back(m[res]);
//			ans.push_back(i);
//			return ans;
//		}
//		else
//			m[v[i]] = i;
//	}
//	return ans;
//}
//
//int main() {
//	vector<int>v;
//	
//	int vl;
//	while (cin >> vl) {
//		v.push_back(vl);
//		if (cin.get() == '\n')
//			break;
//	}
//	int target;cin >> target;
//
//	vector<int>n = twosum(v, target);
//	for (auto i : n)
//		cout << i << "  ";
//
//
//	return 0;
//}