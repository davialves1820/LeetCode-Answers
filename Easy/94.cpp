/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int tree_size(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + tree_size(root->left) + tree_size(root->right);
}

void fill_array(struct TreeNode* root, int* index, int* array) {
    if (root == NULL) {
        return;
    }

    fill_array(root->left, index, array);
    array[(*index)++] = root->val;
    fill_array(root->right, index, array);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = tree_size(root);
    int* array = (int*) malloc((*returnSize) * sizeof(int));
    
    int index = 0;
    fill_array(root, &index, array);
    
    return array;
}
