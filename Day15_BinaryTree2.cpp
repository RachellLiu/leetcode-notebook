/***************************************************************************

  102. Binary Tree Level Order Traversal
  
  层序遍历 广度优先搜索1

***************************************************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

/***************************************************************************

  107. Binary Tree Level Order Traversal II
  
  层序遍历2

***************************************************************************/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/***************************************************************************

  199. Binary Tree Right Side View
  
  层序遍历3

***************************************************************************/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if (root != NULL) que.push(root);
        while (! que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (size == 0) result.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
};

/***************************************************************************

  637. Average of Levels in Binary Tree
  
  层序遍历4

***************************************************************************/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> result;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            double ave = sum/size;
            result.push_back(ave);
        }
        return result;
    }
};

/***************************************************************************

  429. N-ary Tree Level Order Traversal
  
  层序遍历5

***************************************************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> result;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                int childSize = node->children.size();
                for (int i = 0; i < childSize; i++) {
                    que.push(node->children[i]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

/***************************************************************************

  515. Find Largest Value in Each Tree Row
  
  层序遍历6

***************************************************************************/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> result;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int maxi = INT_MIN;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                maxi = max(maxi, node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(maxi);
        }
        return result;
    }
};

/***************************************************************************

  116. Populating Next Right Pointers in Each Node
  
  层序遍历7

***************************************************************************/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                Node* node = que.front();
                que.pop();
                if (size != 0){
                    node->next = que.front();
                }else{
                    node->next = NULL;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            
        }
        return root;
    }
};

/***************************************************************************

  117. Populating Next Right Pointers in Each Node II
  
  层序遍历8
  和上题答案一模一样解决了......

***************************************************************************/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                Node* node = que.front();
                que.pop();
                if (size != 0){
                    node->next = que.front();
                }else{
                    node->next = NULL;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            
        }
        return root;
    }
};

/***************************************************************************

  104. Maximum Depth of Binary Tree
  
  层序遍历9

***************************************************************************/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

/***************************************************************************

  111. Minimum Depth of Binary Tree
  
  层序遍历10

***************************************************************************/

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (node->right == NULL && node->left == NULL) return depth;
            }
        }
        return depth;
    }
};

/***************************************************************************

  226. Invert Binary Tree
  这里用的前序遍历，前后都可以直接按顺序写，但是中序注意把右依然写成左

***************************************************************************/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/***************************************************************************

  101. Symmetric Tree
  这里用的后序遍历

***************************************************************************/

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside && inside;
        return result;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
