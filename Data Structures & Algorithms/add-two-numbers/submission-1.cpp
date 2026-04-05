/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1); //Dummy node to track result list
        ListNode *temp = dummy;
        int carry = 0;

        while(l1 || l2 || carry) { //O(n + m)
            int val1 = l1 ? l1 -> val : 0;
            int val2 = l2 ? l2 -> val : 0;

            int newVal = val1 + val2 + carry;

            carry = newVal / 10;
            newVal %= 10;

            temp -> next = new ListNode(newVal);

            temp = temp -> next;
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }

        ListNode *result = dummy -> next;
        delete dummy;
        return result; //T.C: O(n + m) | S.C: O(1) -> extra, O(max(m, n)) -> output 
    }
};
