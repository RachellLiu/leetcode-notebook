/*****************************************************

  77. Combinations

*****************************************************/

class Solution {
public:
    vector<int> path;
    vector<vector<int>> results;
    void backtracing(int n, int k, int startIndex) {
        if (path.size() == k) {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return results;
    }
};

// 剪枝

class Solution {
public:
    vector<int> path;
    vector<vector<int>> results;
    void backtracing(int n, int k, int startIndex) {
        if (path.size() == k) {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);
        return results;
    }
};
