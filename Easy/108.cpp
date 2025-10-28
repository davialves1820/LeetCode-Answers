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

    // Função recursiva para converter parte do array em uma BST
    TreeNode* sorted_array_to_bs(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;  // evita overflow
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sorted_array_to_bs(nums, left, mid - 1);
        root->right = sorted_array_to_bs(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorted_array_to_bs(nums, 0, nums.size() - 1);
    }
};
