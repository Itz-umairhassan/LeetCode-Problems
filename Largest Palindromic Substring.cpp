//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//string largest;
//bool is_palindromic(string t) {
//	
//	string temp = t;
//	reverse(t.begin(), t.end());
//	
//	if (temp == t)
//		return true;
//	return false;
//}
//
//// actually there are two type of formats for palindrome of a string.. first one is
//// in which there is a character at middle and it's neighbour are same for example
//// 'aba' is palindrome... but there is another format in which two same characters are 
//// at the middle for example 'abba' so we need to write two logics, one for each of them..
//
//int Size_of_largest_palindrome(string st) {
//	int forward, back, len = 0;
//	int sum;
//	int size = st.length();
//
//	// logic for 'aba' like format....
//	for (int i = 0;i < size;i++) {
//		sum = 1;back = i - 1;forward = i + 1;
//		while (back >= 0 && forward < size) {
//			if (st[back] == st[forward]) {
//				sum += 2;
//				back--;forward++;
//			}
//			else
//				break;
//		}
//		if (sum > len) {
//			largest = st.substr(back + 1, sum);
//			len =  sum;
//		}
//		
//	}
//
//	// logic for 'abba' like format...
//	for (int i = 0;i < size;i++) {
//		sum = 1;back = i - 1;forward = i+2 ;
//		if (st[i] == st[i + 1]) {
//			sum++;
//			while (back >= 0 && forward < size) {
//				
//				if (st[back] == st[forward]) {
//					sum += 2;
//					back--;forward++;
//				}
//				else
//					break;
//			}
//		}
//		if (sum > len) {
//			largest = st.substr(back + 1, sum);
//			len = sum;
//		}
//	}
//
//	return len;
//}
//
//int main() {
//	
//	string name;getline(cin,name);
//	cout << is_palindromic(name) << endl;
//	cout << Size_of_largest_palindrome(name);
//	cout << "largest= " << largest << endl;
//	return 0;
//}
//
//string longestPalindrome(string st) {
//	string largest = "";
//	int forward, back, len = 0;
//	int sum;
//	int size = st.length();
//
//	// logic for 'aba' like format....
//	for (int i = 0;i < size;i++) {
//		sum = 1;back = i - 1;forward = i + 1;
//		while (back >= 0 && forward < size) {
//			if (st[back] == st[forward]) {
//				sum += 2;
//				back--;forward++;
//			}
//			else
//				break;
//		}
//		if (sum > len) {
//			largest = st.substr(back + 1, sum);
//			len = sum;
//		}
//
//	}
//
//	// logic for 'abba' like format...
//	for (int i = 0;i < size;i++) {
//		sum = 1;back = i - 1;forward = i + 2;
//		if (st[i] == st[i + 1]) {
//			sum++;
//			while (back >= 0 && forward < size) {
//
//				if (st[back] == st[forward]) {
//					sum += 2;
//					back--;forward++;
//				}
//				else
//					break;
//			}
//		}
//		if (sum > len) {
//			largest = st.substr(back + 1, sum);
//			len = sum;
//		}
//	}
//	return largest;
//}