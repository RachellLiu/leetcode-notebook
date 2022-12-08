/**********************************************************************

  704. Binary Search
  
  Two ways to perform the algorithm: [left, right] and [left, right)
  
  看到面试题里给出的数组是有序数组，都可以想一想是否可以使用二分法。
  Using closed interval is better
***********************************************************************/

// Way1: [left, right]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;  // include the last num
        while (left <= right) {     // <=, as left can be equal to right. eg.[1,1]
            int middle = (left + right) / 2;
            if (target < nums[middle]) right = middle - 1;  // target has already been found to be smaller than middle, there is no need to include middle
            else if (target > nums[middle]) left = middle + 1;  // similar to above
            else return middle;  
        }
        return -1;
    }
};

// Way2: [left, right) 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();   // [left, right) >>>>> [left, right+1]
        while (left < right){      // <, as left cannot be equal to right. eg.[1,1)
            int middle = (left + right) / 2;   
            if (target < nums[middle]) right = middle;     // end at middle-1 
            else if (target > nums[middle]) left = middle + 1; 
            else return middle;
        }
        return -1;
    }
};

/************************************************************************************************************************************

  35. Search Insert Position
  
  Given a sorted array of distinct integers and a target value, return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.
  
  The only difference between two questions is: return left after finishing the while loop. 
  If we cannot find the target in the array:
  We always have: left = right + 1 at the end, because the loop ends when we just meet the condition left > right.
  The last step:             just before the last step:
  1. right = middle - 1; means left = nums[middle] and target < nums[middle] >>>>>> we can put the target at position left
  2. left = left + 1; means right = left and target > nums[middle] >>>>>> we can still put the target at position left
  Special cases:
  1. [2], 1: left = 0, right = 0; middle = 0; right = 1; return left which is 0.
  2. [2], 3: left = 0, right = 0; middle = 0; left = 1; return left which is 1.
  3. [2,4],3: left = 0, right = 1; middle = 0; left = 1; middle = 1; right = 0; return left which is 1.
  
*************************************************************************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (target < nums[middle]) right = middle - 1;
            else if (target > nums[middle]) left = left + 1;
            else return middle;
        }
        return left;    //////
    }
};

/***************************************************************************************************************************************

  34. Find First and Last Position of Element in Sorted Array
  
  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
  If target is not found in the array, return [-1, -1].
  
  Based on Q35, find the left boundary and right boundary.
****************************************************************************************************************************************/

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (target < nums[mid] || (lower && target <= nums[mid])) { // left boundary: use target <= nums[mid]; right boundary: use target < nums[mid]
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target){
            return vector<int>{leftIdx, rightIdx}; 
        } 
        return vector<int>{-1, -1};
    }

};

/**********************************************************************

  27. Remove Element
  
  Two pointers: fast and slow
  fast pointer used to check the item in the array one by one. (right)
  slow pointer used to collect the final arrary. (left)
  
***********************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left += 1;
            }
        }
        return left;
    }
};
