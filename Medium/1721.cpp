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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        
        vector<ListNode*> v;
        ListNode* aux = head;

        while (aux) {
            v.push_back(aux);
            aux = aux->next;
        }

        int n = v.size();
        if (k > n || k <= 0) return head;

        ListNode* first = v[k - 1];
        ListNode* second = v[n - k];

        swap(first->val, second->val);

        return head;

        }
};
