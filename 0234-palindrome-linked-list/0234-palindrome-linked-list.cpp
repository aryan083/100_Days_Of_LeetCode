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
    bool isPalindrome(ListNode* head) {
        if(!head)return true;
        if(!head->next)return true;
        stack<int> st;
        ListNode* slow= head;
        ListNode* fast = head;
        while( fast &&fast->next){
            st.push(slow->val);
            slow= slow->next;
            fast= fast->next->next;

        }
        if (fast) {
            slow = slow->next;
        }
        while(slow && !st.empty()){
            if(slow->val != st.top())return false;
            st.pop();
            slow= slow->next;
        }
        return true;

    }
};