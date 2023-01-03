/******************************************************

  216. Combination Sum III

******************************************************/

class Solution {
public:
    vector<int> path;
    vector<vector<int>> results;
    void backtracing(int targetSum, int k, int sum, int startIndex) {
        if (sum > targetSum) return;
        if (path.size() == k) {
            if (sum == targetSum) results.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtracing(targetSum, k, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracing(n, k, 0, 1);
        return results;
    }
};

/******************************************************

  17. Letter Combinations of a Phone Number

******************************************************/

class Solution {
private:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
public: 
    vector<string> results;
    string s;
    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            results.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracking(digits, index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return results;
        backtracking(digits, 0);
        return results;
    }
};


