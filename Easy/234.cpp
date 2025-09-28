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
    bool isPalindrome(ListNode* head) {
        ListNode* aux = head;
        vector<int> v;

        while (aux != nullptr) {
            v.push_back(aux->val);
            aux = aux->next;
        }
        reverse(v.begin(), v.end());
        aux = head;
        int i = 0;
        while (aux != nullptr && v[i] == aux->val) {
            aux = aux->next;
            i++;
        }
        return i == v.size();
    }
};
