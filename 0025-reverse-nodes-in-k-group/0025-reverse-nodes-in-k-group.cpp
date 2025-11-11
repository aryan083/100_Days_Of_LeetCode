/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 *     ListNode() : val(0), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* node, int k) {
        while (node && k > 1) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {
            ListNode* kth = findKthNode(temp, k);
            if (!kth) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kth->next;
            kth->next = nullptr;

            ListNode* reversedHead = reverse(temp);

            if (temp == head) {
                head = reversedHead;
            } else {
                prevLast->next = reversedHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};
