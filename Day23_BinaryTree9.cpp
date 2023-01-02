/****************************************************

  669. Trim a Binary Search Tree
  
****************************************************/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) return NULL;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

/****************************************************

  108. Convert Sorted Array to Binary Search Tree
  
****************************************************/

class Solution {
public:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = traversal(nums, left, mid-1);
        node->right = traversal(nums, mid+1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size()-1);
    }
};

/****************************************************

  538. Convert BST to Greater Tree
  
****************************************************/

class Solution {
private:
    int pre = 0;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
