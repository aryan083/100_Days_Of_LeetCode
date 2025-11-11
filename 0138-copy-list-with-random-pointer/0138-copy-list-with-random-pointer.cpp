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
       Node* n= head;
       while(n){
        Node* t = n->next;
        n->next = new Node(n->val);
        n->next->next = t;
        n=t;
       } 

       n= head;
       while(n){
        if(n->random) n->next->random = n->random->next;
        
        n=n->next->next;
        
    }
        Node* res=new Node(0),*h=res;
        while(head){
            h->next=head->next;
            h=h->next;

            head->next= head->next->next;
            head=head->next;        

        }
        return res->next;

    }
};