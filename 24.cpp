
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		auto dummy = new ListNode(0);
		dummy->next = head;
		auto prior = dummy;
		prior->next = head;
		auto cur = head;
		while(cur != nullptr && cur->next != nullptr) {
			prior->next = cur->next;
			auto nextNext = cur->next->next;
			cur->next->next = cur;
			cur->next = nextNext;
			prior = cur;
			cur = nextNext;
		}
		// TOOD:
		auto res = dummy->next;
		delete dummy;
		return res;

	}
};

int main() {
	//ListNode *l5 = new ListNode(5);
	ListNode *l4 = new ListNode(4);
	ListNode *l3 = new ListNode(3, l4);
	ListNode *l2 = new ListNode(2, l3);
	ListNode *l1 = new ListNode(1, l2);
	Solution s;
	const auto result = s.swapPairs(l1);
	return 0;
}