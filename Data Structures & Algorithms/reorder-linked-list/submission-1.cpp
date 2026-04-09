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
    ListNode *reverseLL(ListNode *head) {
        ListNode *prev = NULL, *curr = head;

        while(curr) { //O(n)
            ListNode *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        //Find mid of linked list
        ListNode *slow = head, *fast = head;

        while(fast && fast -> next) { //O(n)
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        /* Move to first value of second half and terminate the link to make
        separate lists */
        ListNode *second = slow -> next;
        slow -> next = NULL;
        
        ListNode *head1 = head;
        
        //Reverse the second linked list
        ListNode *head2 = reverseLL(second); //O(n)
        
        //Merge both linked lists as per conditions
        while(head1 && head2) { //O(n)
            ListNode *next1 = head1 -> next;
            head1 -> next = head2;
            head1 = next1;

            ListNode *next2 = head2 -> next;
            head2 -> next = head1;
            head2 = next2;
        } //T.C: O(n), S.C: O(1)
    }
};
