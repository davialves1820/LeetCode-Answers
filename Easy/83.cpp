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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head != nullptr) {
            ListNode* l1 = new ListNode(head->val);
            ListNode* r = l1;
            ListNode* l2 = head;
            head = head->next;
            while (head != nullptr) {
                if (head->val != l2->val) {
                    l1->next = new ListNode(head->val);
                    l1 = l1->next;
                }
                l2 = head;
                head = head->next;
            }
            return r;
        }
        return nullptr;
    }
};
