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
