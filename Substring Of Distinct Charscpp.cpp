#include<iostream>
#include<unordered_map>
using namespace std;

int find_max(string s) {
	int left = 0, right = 0, len = 0;
	unordered_map<char, int>m;
	while (right < s.length()) {
		if (m[s[right]] != 0) { // it means character already exists....
		// place left side indicator after the last found value... but if left indicator
		// has higher value than we take it instead of previous one....
			left = max(left, m[s[right]]);
			
		}
		len = max(len, right - left+1);
		m[s[right]] = right+1;
		right++;
	}

	return len;
}

void print_substring(string s, int st, int end) {
	while (st <= end) {
		cout << s[st];
		st++;
	}
	cout << endl;
}

void find_substring(string s) {
	int left = 0, right = 0;
	unordered_map<char, int>m;
	while (right < s.length()) {
		if (m[s[right]] != 0)
			left = max(left, m[s[right]]);
		m[s[right]] = right + 1;
		print_substring(s, left, right);
		right++;
	}
}

int main() {
	// a 0 , b 4, c 2, 
	// size=3,
	// blank 0,a 1 ,b 2, 3
	string name = "abcbbcade";
	name = " ";
	cout <<"Length of largest substring= "<< find_max(name) << endl;
	cout << "Substrings: "; find_substring(name);
	cout << "Length of largest substring= " << find_max(name) << endl;
}
