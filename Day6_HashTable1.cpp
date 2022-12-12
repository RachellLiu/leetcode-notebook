/*****************************************************

  242. Valid Anagram
  
  数量很小，用数组就可以了；
  数量很大，用set；
  k对应的有value，就用map；
  
  这里优先使用数组，而不是map，因为数组更快
  
******************************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i]-'a']++; 
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

/*****************************************************

  349. Intersection of Two Arrays
  
  这里可以数量很大，所以用unordered_set
  
******************************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); //Directly covert nums1 to unordered_set
        for (int num: nums2) {
            if (nums_set.find(num) != nums_set.end()) {  // If we find this item
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

/*****************************************************

  202. Happy Number
  
  这里可以数量很大，所以用unordered_set
  要注意这个题目里写的无限循环，这就代表可以用哈希表
  
******************************************************/

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10); 
            n /= 10;
        }
        return sum;    
    }

    bool isHappy(int n) {
        unordered_set<int> sumSet;
        while (1) { // loop endlessly until find 1
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (sumSet.find(sum) != sumSet.end()){
                return false;
            }else{
                sumSet.insert(sum);
            }
            n = sum;
        }
    }
};

/*****************************************************

  1. Two Sum
  
  直接找（sum - 这个数）在不在哈希表中就可以了
  
******************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()){
                return {map.find(target - nums[i])->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
