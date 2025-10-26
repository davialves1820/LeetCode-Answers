/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool is_equal(TreeNode* a, TreeNode* b) {
        if (!a && !b) { 
            return true; // Ambos vazios
        }
        if (!a || !b) {
            return false; // Um vazio e outro não
        }
        if (a->val != b->val) {
            return false; // Valores diferentes
        }

        return is_equal(a->left, b->right) && is_equal(a->right, b->left); // Compara os valores cruzados
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }

        return is_equal(root->left, root->right);
    }
};
