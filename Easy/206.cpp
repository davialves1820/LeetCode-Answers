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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* a = head;
        vector<int> r;

        while (a != nullptr) {
            r.push_back(a->val);
            a = a->next;
        } 
        ListNode* reverse = new ListNode();
        ListNode* b = reverse;
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
            b->next = new ListNode(*it);
            b = b->next;
        }
        
        return reverse->next;

    }
};
