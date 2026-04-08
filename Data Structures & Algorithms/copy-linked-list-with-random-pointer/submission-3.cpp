/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node *temp1 = head;
        //Create copies of each node next to the original nodes
        while(temp1) { //O(n)
            Node *temp2 = new Node(temp1 -> val);
            temp2 -> next = temp1 -> next;
            temp1 -> next = temp2;
            temp1 = temp2 -> next;
        }

        Node *newHead = head -> next;

        //Assign random pointer to the copies by using the original nodes
        temp1 = head;
        while(temp1) { //O(n)
            if(temp1 -> random) {
                temp1 -> next -> random = temp1 -> random -> next;
            }
            temp1 = temp1 -> next -> next;
        }

        //Separate the copy from original list
        temp1 = head;
        while(temp1) { //O(n)
            Node *temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            if(temp2 -> next) {
                temp2 -> next = temp2 -> next -> next;
            }
            temp1 = temp1 -> next;
        }

        return newHead; //T.C: O(n) | S.C: O(1)
    }
};
