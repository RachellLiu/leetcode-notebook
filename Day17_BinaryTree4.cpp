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
  
  注意回溯backtracking

****************************************************************/

class Solution {
public:
    void traversal(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string sPath = "";
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
        }
        if (root->left) {
            traversal(root->left, path, result);
            path.pop_back();  //backtracking
        }
        if (root->right) {
            traversal(root->right, path, result);
            path.pop_back();  //backtracking
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        traversal(root, path, result);
        return result;
    }
};

/****************************************************************

  404. Sum of Left Leaves

****************************************************************/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        int leftN = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            leftN += root->left->val;
        }
        int rightN = sumOfLeftLeaves(root->right);
        int sum = leftN + rightN;
        return sum;
    }
};
