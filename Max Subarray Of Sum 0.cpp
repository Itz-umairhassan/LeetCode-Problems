#include<iostream>
#include<unordered_map>
using namespace std;

int find_max(int arr[], int size) {
	unordered_map<int, int>m;
	int  curr = 0, sum = 0;
	for (int i = 0;i < size;i++) {
		curr += arr[i];
		if (curr == 0)
			sum = i + 1; // as we are finding prefix so it will be the largest subarray
		else {
			if (m.find(curr) != m.end()) // value of current sum already exist
				sum = max(sum, i - m[curr] );
			else
				m[curr] = i;
		}
	}
	return sum;
}
int main() {
	int arr[] = { 3,-3,5,6,4,-10 };
	cout << find_max(arr, 6);
	return 0;
}