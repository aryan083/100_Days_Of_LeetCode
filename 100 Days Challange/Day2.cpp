//3217. Delete Nodes From Linked List Present in Array
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> numss(nums.begin(), nums.end());

        // Create a dummy node to handle the case where the head node is removed
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while (curr->next) {
            if (numss.count(curr->next->val)) {
                // Skip the node if its value is in the set
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Optional: Free the memory of the removed node
            } else {
                curr = curr->next; // Move to the next node
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};
