/************************************************************

  235. Lowest Common Ancestor of a Binary Search Tree
  
  用迭代法更简单
  
************************************************************/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};

/************************************************************

  701. Insert into a Binary Search Tree
  
************************************************************/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        if (val > root->val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

/************************************************************

  450. Delete Node in a BST
  
************************************************************/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if (root->left == NULL&& root->right != NULL) {
                TreeNode* rootRight = root->right;
                delete root;
                return rootRight;
            }
            else if (root->left != NULL && root->right == NULL) {
                TreeNode* rootLeft = root->left;
                delete root;
                return rootLeft;                
            }
            else {
                TreeNode* cur = root->right;
                while (cur->left != NULL) cur = cur->left;
                cur->left = root->left;
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
        }
        if (key < root->val) root->left = deleteNode(root->left,key);
        if (key > root->val) root->right = deleteNode(root->right,key);
        return root;
    }
};

