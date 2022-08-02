#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};


void traversal(ListNode* head) {
	ListNode* temp = head;
	while (temp != NULL) {
		cout << temp->val << "  ";
		temp = temp->next;
	}
}

void add_ListNode(ListNode* head, int val) {
	if (head == NULL)
		head = new ListNode(val);
	else {
		ListNode* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new ListNode(val);
	}
}

ListNode* addnumbers(ListNode* l1, ListNode*l2) {
	ListNode* temp1 = l1;// 2 4 9 2
	ListNode* temp2 =l2;// 5 6 4
	int remain = 0, sum;
	ListNode* third = NULL;

	third = new ListNode((l1->val +l2->val) % 10);
	remain += (l1->val +l2->val) / 10;
	ListNode* temp3 = third;
	temp1 = temp1->next;
	temp2 = temp2->next;
	// now add remaining values....
	while (temp1 != NULL && temp2 != NULL) {
		sum = temp1->val + temp2->val + remain;
		temp3->next = new ListNode(sum % 10);
		remain = sum / 10;
		temp3 = temp3->next;
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	 // one list remains......
	while (temp1 != NULL) {
		sum = temp1->val + remain;
		temp3->next = new ListNode(sum % 10);
		remain = sum / 10;
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	
	while (temp2 != NULL) {
		sum = temp2->val + remain;
		temp3->next = new ListNode(sum % 10);
		remain = sum / 10;
		temp3 = temp3->next;
		temp2 = temp2->next;
	}

	if (remain != 0) {
		temp3->next = new ListNode(remain);
	}
	return third;
}
int main() {
	ListNode* head = new ListNode(2);
	head->next = new ListNode(4);
	head->next->next = new ListNode(9);
	head->next->next->next = new ListNode(2);

	ListNode*l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode* third = addnumbers(head,l2);
	traversal(third);cout << endl;
	return 0;
}