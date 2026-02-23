/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    var dummy = new ListNode(null, null);
    var cur = dummy;
    var carry = false;
    while(l1 !== null || l2 !== null) {
        var l1Num = 0;
        if(l1 !== null) {
            l1Num = l1.val;
            l1 = l1.next;
        }
        var l2Num = 0;
        if(l2 !== null) {
            l2Num = l2.val;
            l2 = l2.next;
        }
        var result = l1Num + l2Num;
        if(carry) {
            result += 1;
            carry = false;
        }
        if(result >= 10) {
            carry = true;
            result %= 10;
        }
        cur.next = new ListNode(result, null);
        cur = cur.next;
    }
    if(carry) {
        cur.next = new ListNode(1, null);
    }
    const ret = dummy.next;
    dummy.next = null
    return ret;
};