class Solution {
public:
    ListNode* reverseLL(ListNode* head,int counter) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr != NULL && counter > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            counter--;
        }

        head->next = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;

        int counter = right - left + 1;

        ListNode* newHead = reverseLL(start, counter);

        prev->next = newHead;

        return dummy.next;
    }
};
