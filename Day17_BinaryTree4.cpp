/****************************************************************

  110. Balanced Binary Tree

****************************************************************/

class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        else return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if (getHeight(root) == -1) return false;
        else return true;
    }
};

/****************************************************************

  257. Binary Tree Paths

****************************************************************/

