/*******************************************************************

  104. Maximum Depth of Binary Tree
  
  上次用层序遍历写了，很长很麻烦
  高度是到叶子节点的高度，深度是到root的深度
  高度用后序遍历，深度用前序遍历
  根节点的高度就是最大深度
  这里用后序遍历的精简代码

*******************************************************************/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

/*******************************************************************

  111. Minimum Depth of Binary Tree
  
  依然后序遍历，但要注意一个特殊情况，就是有一边是NULL的情况

*******************************************************************/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftL = minDepth(root->left);
        int rightL = minDepth(root->right);
        if (root->left == NULL && root->right != NULL) return 1+rightL;
        if (root->right == NULL && root->left != NULL) return 1+leftL;
        return 1+min(leftL, rightL);
    }
};

/*******************************************************************

  222. Count Complete Tree Nodes
  
  用完全二叉树的特性可以节省时间复杂度

*******************************************************************/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            leftDepth ++;
            left = left->left;
        }
        while (right) {
            rightDepth ++;
            right = right->right;
        }
        if (leftDepth == rightDepth) return (2<<leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
