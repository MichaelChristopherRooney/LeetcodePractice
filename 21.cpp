
 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == nullptr) {
			return list2;
		}
		if(list2 == nullptr) {
			return list1;
		}
		ListNode *dummy = new ListNode(0);
		ListNode *cur = dummy;
		while(list1 != nullptr && list2 != nullptr) {
			if(list1->val < list2->val) {
				cur->next = list1;
				list1 = list1->next;
			} else {
				cur->next = list2;
				list2 = list2->next;
			}
			cur = cur->next;
		}
		if(list1 != nullptr) {
			cur->next = list1;
		}
		if(list2 != nullptr) {
			cur->next = list2;
		}
		auto ret = dummy->next;
		delete dummy;
		return ret;

	}
};

int main() {
	//ListNode *l5 = new ListNode(5);
	//ListNode *l4 = new ListNode(4, l5);
	ListNode *l13 = new ListNode(4);
	ListNode *l12 = new ListNode(2, l13);
	ListNode *l11 = new ListNode(1, l12);
	ListNode *l23 = new ListNode(3);
	ListNode *l22 = new ListNode(2, l23);
	ListNode *l21 = new ListNode(1, l22);
	Solution s;
	const auto result = s.mergeTwoLists(l11, l21);
	return 0;
}