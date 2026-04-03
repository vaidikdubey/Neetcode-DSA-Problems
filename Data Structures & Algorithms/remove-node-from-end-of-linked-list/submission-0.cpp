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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;

        while(temp) { //O(n)
            len++;
            temp = temp -> next;
        }

        int delLen = len - n;
        if(delLen == 0) return head -> next;

        temp = head;
        for(int i = 0; i < delLen - 1; i++) { //O(len - n)
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;

        return head; //T.C: O(n), S.C: O(1)
    }
};
