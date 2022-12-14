/********************************************************************************

  454. 4Sum II
  
  先遍历前两个数组，再遍历后两个数组，时间复杂度为n^2，要比其他方式更快
  注意最后count加的是map[target]，而不是1，因为前两个数组的和有多少种就要加多少种

*********************************************************************************/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> map;
        int count = 0;
        for (int a: nums1) {
            for (int b: nums2) {
                map[a+b]++;
            }
        }
        for (int c: nums3) {
            for (int d: nums4) {
                int target = 0 - (c + d);
                if (map.find(target) != map.end()) {
                    count += map[target];
                }
            }
        }
        return count;
    }
};

/*******************************************************************

  383. Ransom Note
  
  用数组就可以，因为26个字母，这样比unordered_map快

********************************************************************/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()){
            return false;
        }
        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++) {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

/*******************************************************************

  15. 3Sum
  
  可以用哈希法，但是去重非常复杂，不如用双指针。
  先做排序处理。
  一个大的for循环，里面left和right指针不停地移动来满足和为0。

********************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return results;
            if ((i > 0) && (nums[i] == nums[i-1])) continue;  //去重只能i-1因为这样不会影响同一个三元组里的left
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    results.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while ((left < right) && (nums[left] == nums[left+1])) left++;
                    while ((left < right) && (nums[right] == nums [right-1])) right--;
                    left++;
                    right--;
                }
            }
        }
        return results;
    }
};

/*******************************************************************

  18. 4Sum
  
  注意去重和剪枝

********************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝
            if (nums[k] > target && nums[k] >= 0){
                break;
            }
            // 去重
            if (k > 0 && nums[k] == nums[k-1]){
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 剪枝
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }
                // 去重
                if (i > k + 1 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if ((long)nums[k]+nums[i]+nums[left]+nums[right] > target) {
                        right--;
                    }else if ((long)nums[k]+nums[i]+nums[left]+nums[right] < target){
                        left++;
                    }
                    else{
                        results.push_back(vector<int> {nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right-1]) right--;
                        while (left <right && nums[left] == nums[left+1]) left++;
                        right--;
                        left++;
                    }

                }
            }
        }
        return results;
    }
};
