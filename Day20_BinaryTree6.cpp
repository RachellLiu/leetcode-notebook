/********************************************************************

  654. Maximum Binary Tree
  
  构造二叉树都用前序遍历
  
********************************************************************/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        int maxValue = INT_MIN;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                index = i;
            }
        }
        node->val = maxValue;
        if (index > 0) {
            vector<int> leftVec(nums.begin(),nums.begin()+index);
            node->left = constructMaximumBinaryTree(leftVec); 
        }
        if (index < nums.size() - 1) {
            vector<int> rightVec(nums.begin()+index+1, nums.end());
            node->right = constructMaximumBinaryTree(rightVec);
        }
        return node;
    }
};

/********************************************************************

  617. Merge Two Binary Trees
  
********************************************************************/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

/********************************************************************

  700. Search in a Binary Search Tree
  
********************************************************************/

// 递归法
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        if (val < root->val) return searchBST(root->left, val);
        if (val > root->val) return searchBST(root->right, val);
        return NULL;
    }
};

// 迭代法
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (val < root->val) root = root->left;
            else if (val > root->val) root = root->right;
            else if (val == root->val) return root;
        }
        return NULL;
    }
};

/********************************************************************

  98. Validate Binary Search Tree
  
********************************************************************/


