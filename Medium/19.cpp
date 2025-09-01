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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* aux = head;
        
        while (aux != nullptr) {
            v.push_back(aux);
            aux = aux->next;
        }
        int tam = v.size();
        if (tam == n) {
            return head->next;
        }
        aux = v[tam - n - 1];
        ListNode* a =  v[tam - n];
        aux->next = a->next;
        return head;
    }
};
