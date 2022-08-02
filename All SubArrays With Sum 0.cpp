#include<iostream>
#include<unordered_map>
using namespace std;

void print_arrays(int arr[], int st, int end) {
	for (int i = st;i <= end;i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void find_subarrays(int arr[], int size) {
	int sum = 0;
	unordered_map<int, int>m;
	for (int i = 0;i < size;i++) {
		sum += arr[i];
		if (sum == 0) // it means that subarray following to this has sum zero....
			print_arrays(arr, 0, i);
		else {
			if (m.find(sum) != m.end())
				print_arrays(arr, m[sum] + 1, i);
			else
				m[sum] = i;
		}
	}
}
int main() {
	int arr[] = { 3,4,-4,5,6,-5,-2 };
	find_subarrays(arr, 7);
	return 0;
}