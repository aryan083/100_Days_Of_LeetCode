// 2807. Insert Greatest Common Divisors in Linked List
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

    int GCD(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            int val1 = curr->val;
            int val2 = curr->next->val;  
            int gcdVal = GCD(val1, val2);
            
            ListNode* newNode = new ListNode(gcdVal, curr->next);
            curr->next = newNode;
            curr = curr->next->next;
        }
        return head;
    }
};