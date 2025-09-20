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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* l = head;
        ListNode* ant = nullptr;
        
        while (l != nullptr) {
            if (l->val == val) {
                if (ant == nullptr) {
                    head = l->next;
                } else {
                    ant->next = l->next;
                }
                ListNode* aux = l;
                l = l->next;
                delete aux;
            } else {
                ant = l;
                l = l->next;
            }
        }
        return head;
    }
};
