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
  
  二叉搜索树一定用中序遍历
  
****************************************************/

class Solution {
public:
    TreeNode* pre = NULL;
    int count = 0, maxCount = 0;
    vector<int> result;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->left);
        if (pre == NULL) count = 1;
        else if (pre->val == cur->val) count++;
        else count = 1;
        pre = cur;
        if (count == maxCount) result.push_back(cur->val);
        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        traversal(cur->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        //如果上面的pre，count，maxCount都是private的话，这里需要定义一下
        traversal(root);
        return result;
    }
};

/****************************************************

  236. Lowest Common Ancestor of a Binary Tree
  
  回溯
  
****************************************************/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left != NULL && right !=NULL) return root;
        else if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else return NULL;
    }
};
