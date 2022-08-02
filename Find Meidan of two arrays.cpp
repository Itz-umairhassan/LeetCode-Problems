#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<double, vector<double>>max_heap;
priority_queue<double, vector<double>, greater<double>>min_heap;
void add(double value) {
	if (max_heap.size() == min_heap.size()) {
		if (max_heap.size() == 0) {
			max_heap.push(value);
			return;
		}
		if (value < max_heap.top())
			max_heap.push(value);
		else
			min_heap.push(value);
	}
	else { 
		if (max_heap.size() > min_heap.size()) {
			if (value >= max_heap.top())
				min_heap.push(value);
			else {
				double temp = max_heap.top();
				max_heap.pop();
				max_heap.push(value);
				min_heap.push(temp);
			}
		}
		else {
			if (value <= min_heap.top())
				max_heap.push(value);
			else {
				double temp = min_heap.top();
				min_heap.pop();
				min_heap.push(value);
				max_heap.push(temp);
			}
		}
	}
}

double get_median() {
	if (max_heap.size() == min_heap.size())
		return (max_heap.top() + min_heap.top()) / 2.0;
	if (max_heap.size() > min_heap.size())
		return max_heap.top();
	return min_heap.top();
}

double median(vector<double>v1, vector<double>v2) {
	for (auto i : v1)
		add(i);
	for (auto i : v2)
		add(i);
	return get_median();
}
int main() {
	vector<double>v1;

	vector<double>v2;
	double v;
	while (cin >> v) {
		v1.push_back(v);
		if (cin.get() == '\n')
			break;
	}
	while (cin >> v) {
		v2.push_back(v);
		if (cin.get() == '\n')
			break;
	}

	cout <<"median= " << median(v1, v2) << endl;
	
	return 0;
}