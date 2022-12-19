/*************************************************************************

  239. Sliding Window Maximum
  
  写一个单调队列的class
  
*************************************************************************/

class Solution {
private:
    class myDeque {
        public:
            deque<int> que;
            void pop(int value) {
                if (!que.empty() && value == que.front()) {
                    que.pop_front();
                }
            }
            void push(int value) {
                while (!que.empty() && value > que.back()) {
                    que.pop_back();
                }
                que.push_back(value);
            }
            int front () {
                return que.front();
            }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myDeque que;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};

/*************************************************************************

  347. Top K Frequent Elements
  
*************************************************************************/

