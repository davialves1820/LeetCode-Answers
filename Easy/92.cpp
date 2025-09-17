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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* prev = d;
        
        prev->next = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* prox = start->next;

        for (int i = 0; i < right - left; i++) {
            start->next = prox->next;
            prox->next = prev->next;
            prev->next = prox;
            prox = start->next;
        }
        return d->next;

    }
};
