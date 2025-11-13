/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //  if(head==NULL || head->next== NULL) return head;
        ListNode* saslu =head;
        ListNode* kachbo=head;
        while(saslu !=NULL && saslu->next !=NULL){
            kachbo=kachbo->next;
            saslu =saslu->next->next;
            if(saslu==kachbo){break;}
        }
        if(!saslu|| !saslu->next)return nullptr;
        saslu=head;
        while(saslu!=kachbo){
            saslu=saslu->next;
            kachbo=kachbo->next;
        }
        return kachbo;
   
    }
};