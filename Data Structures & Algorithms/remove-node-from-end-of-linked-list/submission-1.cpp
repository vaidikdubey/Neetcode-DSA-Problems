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
        ListNode *dummy = new ListNode(0, head); //Dummy node
        ListNode *first = dummy;
        ListNode *second = head;

        //O(n)
        while(n > 0) { //Move second pointer n nodes ahead of first
            second = second -> next;
            n--;
        }

        //O(N - n)
        while(second) { //Move both pointer by 1 node till second reaches end
            first = first -> next;
            second = second -> next;
        }

        //Update next pointers to delete required node
        //O(1)
        first -> next = first -> next -> next;
        
        return dummy -> next; //T.C: O(n) | S.C: O(1)
    }
};
