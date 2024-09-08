// 725. Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        ListNode* curr=head;
        int len=0;
        while(curr){
            curr=curr->next;
            len++;
        }

        int base_len=len/k; //no. of array we need to return
        int extra_nodes=len%k; // size of each array that we return
        curr=head;
        vector <ListNode*>res;
 
        for (int i = 0; i < k; i++) {
            res.push_back(curr); // Store the head of the current part
            
            // Determine the length of the current part
            int part_len = base_len + (i < extra_nodes ? 1 : 0);
            
            // Move curr to the end of the current part
            for (int j = 0; j < part_len - 1 && curr; j++) {
                curr = curr->next;
            }
            
            // If curr is valid, split the list
            if (curr) {
                ListNode* next_node = curr->next;
                curr->next = nullptr; // Split the list
                curr = next_node; // Move curr to the next node
            }
        }
    return res;

    }
};