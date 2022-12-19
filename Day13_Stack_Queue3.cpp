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
  
  用小顶堆
  
*************************************************************************/

class Solution {
public:
    class myComparison {
        public:
            bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
                return lhs.second > rhs.second;
            }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] ++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, myComparison> pri_que;
        for(unordered_map<int,int>::iterator it=map.begin();it!=map.end();it++){
            pri_que.push(*it);
            if (pri_que.size()>k) {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
