/********************************************************

  144. Binary Tree Preorder Traversal 前序遍历（中左右）
  
  1.确定递归函数的参数和返回值
  2.确定终止条件
  3.确定单层递归的逻辑
  
********************************************************/

class Solution {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

/********************************************************

  145. Binary Tree Postorder Traversal 后序遍历（左右中）
  
********************************************************/

class Solution {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

/********************************************************

  94. Binary Tree Inorder Traversal 中序遍历 (左中右)
  
********************************************************/

class Solution {
public:
    void traversal (TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
