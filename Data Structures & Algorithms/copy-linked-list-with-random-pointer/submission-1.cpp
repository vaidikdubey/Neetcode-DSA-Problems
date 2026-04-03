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

        Node *newHead = new Node(head -> val); //S.C: O(n)
        Node *temp1 = newHead, *temp2 = head -> next;

        //Create next copy of list
        while(temp2) { //O(n)
            Node *tempNode = new Node(temp2 -> val);
            temp1 -> next = tempNode;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        
        //Create map for original:copy mapping
        unordered_map<Node *, Node *> copyMap; //S.C: O(n)
        temp1 = newHead;
        temp2 = head;

        while(temp1 && temp2) { //O(n)
            copyMap[temp2] = temp1;
            temp2 = temp2 -> next;
            temp1 = temp1 -> next;
        }

        //Assign random pointers to new list using map
        temp1 = newHead;
        temp2 = head;

        while(temp1 && temp2) { //O(n)
            temp1 -> random = copyMap[temp2 -> random];
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        return newHead; //T.C: O(n) | S.C: O(n)
    }
};
