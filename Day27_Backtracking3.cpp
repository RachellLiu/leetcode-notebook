/******************************************************

  39. Combination Sum
  
  backtracking的步骤：
  1.确定递归函数的参数返回值
  2.确定终止条件
  3.确定单层递归逻辑

******************************************************/

class Solution {
private:
    vector<int> path;
    vector<vector<int>> results;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            results.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); 
            // i not i+1 "The same number may be chosen from candidates an unlimited number of times."
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return results;
    }
};

/******************************************************

  40. Combination Sum II

******************************************************/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtacking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtacking(candidates, target, sum, i+1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtacking(candidates, target, 0, 0, used);
        return result;
    }
};

/******************************************************

  131. Palindrome Partitioning

******************************************************/

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(const string& s, int startIndex) {
        if (startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};

