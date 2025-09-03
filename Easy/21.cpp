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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* l3 = nullptr;

       while (list1 != nullptr) {
            l3 = insert_order(l3, list1->val);
            list1 = list1->next;
       }
       while (list2 != nullptr) {
            l3 = insert_order(l3, list2->val);
            list2 = list2->next;
       }
       return l3;
    }

    ListNode* insert_order(ListNode* l, int v) {
        ListNode* novo = new ListNode(v);
        ListNode* ant = nullptr;
        ListNode* prox = l;

        while (prox != nullptr && prox->val < v) {
            ant = prox;
            prox = prox->next;
        }
        if (ant == nullptr) {
            novo->next = prox;
            l = novo;
        } else {
            novo->next = ant->next;
            ant->next = novo;
        }
        return l;
    }
};
