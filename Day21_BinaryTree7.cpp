/****************************************************

  530. Minimum Absolute Difference in BST
  
****************************************************/

class Solution {
public:
    int result = INT_MAX;
    TreeNode* pre = NULL;
    void taversal(TreeNode* root){
        if (root == NULL) return;
        taversal(root->left);
        if (pre != NULL) result = min(result, root->val - pre->val);
        pre = root;
        taversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return NULL;
        taversal(root);
        return result;
    }
};

/****************************************************

  501. Find Mode in Binary Search Tree
  
****************************************************/

