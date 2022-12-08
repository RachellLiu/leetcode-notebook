/**********************************************************************************************

  977. Squares of a Sorted Array
  
  Given an integer array nums sorted in non-decreasing order, return 
  an array of the squares of each number sorted in non-decreasing order.
  
  一定是从两边向中间递减的，所以用two pointer，从两边向中间由大到小地记录
  
************************************************************************************************/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;){  //这里可以不写i++,j--
            if (nums[i] * nums[i] >= nums[j] * nums[j]){
                result[k] = nums[i] * nums[i];
                i++;
                k--;
            }else{
                result[k] = nums[j] * nums[j];
                j--;
                k--;
            }
        }
        return result;
    }
};

/**********************************************************************************************************

  209. Minimum Size Subarray Sum
  
  Given an array of positive integers nums and a positive integer target, return the minimal length of a 
  subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
  
  滑动窗口：i:窗口起始位置; j:窗口终止位置; 
  窗口：满足sum >= target条件的连续子数组.
  先找到终止位置，再逐个减少找起始位置。
  
************************************************************************************************************/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, i = 0, subL = 0, result = INT32_MAX;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subL = j - i + 1;
                result = min(result, subL);
                sum = sum - nums[i];
                i++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

/**********************************************************************************************************

  59. Spiral Matrix II
  
  Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
  
  注意循环不变量是什么：是每次便利操作的规则都应该是一样的。
  这里使用左闭右开区间[a,b)，这样每次最后一个都留给下一转。
  
************************************************************************************************************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int startx = 0, starty = 0, count = 1, offset = 1, loop = n/2;
        int i, j;
        while (loop--) {
            for (j = starty; j < n - offset; j++) {
                ans[startx][j] = count++; 
            }
            for (i = startx; i < n - offset; i++) {
                ans[i][j] = count++;
            }
            for (; j > starty; j--) {
                ans[i][j] = count++;
            }
            for (; i > startx; i--) {
                ans[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n % 2 == 1) {
            ans[n/2][n/2] = count++;
        }
        return ans;
    }
};
