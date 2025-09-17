/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* cabeca = head;
        ListNode* aux = head;
        while (aux != nullptr && aux->next != nullptr) {
            cabeca = cabeca->next;
            aux = aux->next->next;
            if (cabeca == aux) {
                return true;
            }
        }
        return false;
    }
};
