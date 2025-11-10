/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* getTail(Node* head) {
        if(!head) {
            return nullptr;
        }
        if(head->next) {
            return getTail(head->next);
        }
        return head;
    }
    Node* flatten(Node* head) {
        if(!head){
            return nullptr;
        }

        if(head->child) {
            Node* flatList = flatten(head->child);
            if(flatList) {
                Node* tail = getTail(flatList);
                //Store current Next Node
                Node* nextNode = head->next;
                //attach current head with flatList;
                head->next = flatList;
                flatList->prev = head;

                //Detach child node
                head->child = nullptr;

                //attach tail of flatList with previous next Node
                tail->next = nextNode;
                if(nextNode) {
                    nextNode->prev = tail;
                }
            }
        }

        flatten(head->next);
        return head;
    }
};