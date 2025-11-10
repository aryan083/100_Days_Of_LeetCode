class Solution {
public:
    ListNode* reverseLL(ListNode* head,int counter) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next_node = NULL;

        while (curr != NULL && counter > 0) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            counter--;
        }

        // head becomes the tail, connect it to remaining part
        head->next = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;

        // move prev to the node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // start reversing from prev->next
        ListNode* start = prev->next;

        int counter = right - left + 1;

        // reverse and get new head of reversed part
        ListNode* newHead = reverseLL(start, counter);

        // connect prev to new head of reversed part
        prev->next = newHead;

        return dummy.next;
    }
};
