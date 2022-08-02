#include<iostream>
#include<queue>
using namespace std;
queue<int>q;
long long mult = 1;
void add_to_queue(int i) {
	while (i > 9 || i< -9) {
		q.push(i%10);
		i /= 10;
		mult *= 10;
	}
	q.push(i);
}

long long reverse(int x) {
	add_to_queue(x);
	long long fin = 0;
	while (!q.empty()) {
		fin+= (q.front() * mult);
		mult /= 10;
		q.pop();
	}
	return fin;
}
void show() {
	while (!q.empty()) {
		cout << q.front() << "  ";
		q.pop();
	}
}
int main() {
	int i;cin >> i;
	
	long long ans = reverse(i);
	if (ans > 2147483647 || ans < -2147483648) {
		cout << "out of bound" << ans;
	}
	else
		cout <<"in range= "<< ans;
	return 0;
}