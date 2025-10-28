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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* aux = head;
        while (aux != NULL && aux->next!= NULL) {
            int a = aux->val;
            aux->val = aux->next->val;
            aux->next->val = a;
            
            if (aux->next->next != NULL) {
                aux = aux->next->next;
            } else {
                break;
            }
            
        }
        return head;
    }
};
