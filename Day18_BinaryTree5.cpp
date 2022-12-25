/******************************************************

  513. Find Bottom Left Tree Value

******************************************************/

// 层序遍历简单很多
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        int result;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (i == 0) result = node->val;
            }
        }
        return result;
    }
};

// 递归法相对难一点

class Solution {
public:
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left) {
            traversal(root->left, depth + 1); 
        }
        if (root->right) {
            traversal(root->right, depth + 1); 
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};

/******************************************************

  112. Path Sum

******************************************************/

class Solution {
public:
    bool traversal(TreeNode* root, int count) {
        if (root->left == NULL && root->right == NULL && count == 0) return true;
        if (root->left == NULL && root->right == NULL && count != 0) return false;
        if (root->left) {
            count -= root->left->val;
            if (traversal(root->left,count)) return true;
            count += root->left->val;
        }
        if (root->right) {
            count -= root->right->val;
            if (traversal(root->right,count)) return true;
            count += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};

/******************************************************

  112. Path Sum

******************************************************/
