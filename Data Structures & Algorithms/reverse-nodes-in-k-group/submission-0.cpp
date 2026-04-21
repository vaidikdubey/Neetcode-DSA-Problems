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
    ListNode *getkth(ListNode *curr, int k) {
        while(curr && k > 0) {
            curr = curr -> next;
            k--;
        }

        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPrev = dummy;

        while(true) {
            ListNode *kth = getkth(groupPrev, k);
            if(!kth) break;

            ListNode *groupNext = kth  -> next;

            ListNode *prev = kth -> next;
            ListNode *curr = groupPrev -> next;

            while(curr != groupNext) {
                ListNode *next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            ListNode *temp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = temp;
        }

        return dummy -> next; //O(n), O(1)
    }
};
