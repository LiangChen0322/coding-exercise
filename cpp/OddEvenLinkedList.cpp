/**
 * LeetCode: Odd Even Linked List
 * https://leetcode.com/problems/odd-even-linked-list/
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void ListPrint(ListNode* head)
{
	while (1) {
		if (head == NULL) {
			cout << "NULL" << endl;
			return;
		}
		else{
			cout << head->val << " -> ";
			head = head->next;
		}
	}
}

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
			if (head == NULL || head->next == NULL)
				return head;
			ListNode *odd = head;
			ListNode *even = head->next;
			while (even != NULL && even->next != NULL) {
				ListNode *evenh = odd->next;
				ListNode *temp = even->next;

				even->next = temp->next;
				even = even->next;
				odd->next = temp;
				temp->next = evenh;
				odd = temp;
			}
			return head;
	}
};

void test1()
{
	Solution Sol;
	ListNode *L1 = new ListNode(1);

	ListNode *Res = Sol.oddEvenList(L1);
	ListPrint(Res);
}

void test2()
{
	Solution Sol;
	ListNode *L1 = new ListNode(1);
	L1->next = new ListNode(2);

	ListNode *Res = Sol.oddEvenList(L1);
	ListPrint(Res);
}

void test3()
{
	Solution Sol;
	ListNode *L1 = new ListNode(1);
	ListNode *L2 = new ListNode(2);
	ListNode *L3 = new ListNode(3);

	L1->next = L2;
	L2->next = L3;

	ListNode *Res = Sol.oddEvenList(L1);
	ListPrint(Res);
}

void test4()
{
	Solution Sol;
	ListNode *L1 = new ListNode(1);
	ListNode *L2 = new ListNode(2);
	ListNode *L3 = new ListNode(3);
	ListNode *L4 = new ListNode(4);
	ListNode *L5 = new ListNode(5);
	ListNode *L6 = new ListNode(6);

	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = L5;
	L5->next = L6;

	ListNode *Res = Sol.oddEvenList(L1);
	ListPrint(Res);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
