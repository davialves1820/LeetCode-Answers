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

    int check_height(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_height = check_height(root->left);
        
        if (left_height == -1) {
            return -1; // Não balanceada
        }
        
        int right_height = check_height(root->right);
        
        if (right_height == -1) {
            return -1; // Não balanceada
        }
        
        if (abs(left_height - right_height) > 1){
            return -1; // Diferença maior que 1: não balanceada
        }

        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return check_height(root) > -1;
    }
};
