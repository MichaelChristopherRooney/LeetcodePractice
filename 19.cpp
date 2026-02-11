 struct ListNode {
 	int val;
 	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		auto nPlus1Back = new ListNode(0);
		nPlus1Back->next = head;
		auto copy = nPlus1Back;
		// Spec says that size is at least n.
		auto cur = head;
		for(int i = 0; i < n; i++) {
			cur = cur->next;
		}
		// Handle the case where size == n.
		if(cur == nullptr) {
			delete nPlus1Back;
			return head->next;
		}
		while(cur != nullptr) {
			nPlus1Back = nPlus1Back->next;
			cur = cur->next;
		}
		nPlus1Back->next = nPlus1Back->next->next;
		delete copy;
		return head;


	}
};

int main() {
	//ListNode *l5 = new ListNode(5);
	//ListNode *l4 = new ListNode(4, l5);
	//ListNode *l3 = new ListNode(3, l4);
	ListNode *l2 = new ListNode(2);
	ListNode *l1 = new ListNode(1, l2);

	Solution s;
	auto head = s.removeNthFromEnd(l1, 1);
	return 0;
}