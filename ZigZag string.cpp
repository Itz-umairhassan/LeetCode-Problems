#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<int, vector<char>>m;
	string s;cin >> s;
	int size = s.length();
	int row;cin >> row;
	int curr_row = 0;
	bool up = false, down = true;
	for (int i = 0;i < size;i++) {
		if (up)
			curr_row--;
		else
			curr_row++;

		m[curr_row].push_back(s[i]);
	

		if (curr_row >= row) {
			up = true;
			down = false;
		}
		else if (curr_row <= 1) {
			up = false;
			down = true;
		}
	}
	string temp = "";

	for (int i = 1;i <= row;i++) {
		for (auto j : m[i])
			temp+= j;
	}
	for (int i = 0;i < temp.length();i++) {
		cout << temp[i];
	}
	return 0;
}