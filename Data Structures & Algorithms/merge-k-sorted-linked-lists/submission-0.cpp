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
    ListNode *mergeLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        while(list1 && list2) {
            int val;
            if(list1 -> val <= list2 -> val) {
                val = list1 -> val;
                list1 = list1 -> next;
            }
            else {
                val = list2 -> val;
                list2 = list2 -> next;
            }

            temp -> next = new ListNode(val);
            temp = temp -> next;
        }

        //Finish remaining list
        while(list1) {
            temp -> next = new ListNode(list1 -> val);
            list1 = list1 -> next;
            temp = temp -> next;
        }

        while(list2) {
            temp -> next = new ListNode(list2 -> val);
            list2 = list2 -> next;
            temp = temp -> next;
        }

        return dummy -> next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        //Edge cases
        if(n == 0) return NULL;
        if(n == 1 && lists[0] == NULL) return 0;
        
        bool allNull = true;
        for(int i = 0; i < n; i++) {
            if(lists[i] != NULL) allNull = false;
        }

        if(allNull) return NULL;

        for(int i = 1; i < n; i++) {
            lists[i] = mergeLists(lists[i], lists[i - 1]);
        }

        return lists[n - 1];
    }
};
