/*****************************************************************

  28. Find the Index of the First Occurrence in a String
  
  KMP algorithm:
  如果用暴力解法时间复杂度是O(文本串长度*模式串长度)，而KMP会小很多
  先找前缀表getNext，步骤:
  1.初始化 2.前后缀不相同的情况 3.前后缀相同的情况 4.next 
  重点：如果遇到冲突，要跳到前一个数所对应的前缀表的位置上！————循环不变量
  
  关于指针回溯求next的理解:
  每次求next[i]，可看作前缀与后缀的一次匹配，在该过程中就可以用上之前所求的next，若匹配失败，则像模式串与文本串匹配一样，将指针移到next[j-1]上。
  求next过程实际上是dp（动态规划），只与前一个状态有关：
  若不匹配，一直往前退到0或匹配为止
  若匹配，则将之前的结果传递：
  因为之前的结果不为0时，前后缀有相等的部分，所以j所指的实际是与当前值相等的前缀，可视为将前缀从前面拖了过来，就不必将指针从前缀开始匹配了，所以之前的结果是可以传递的。

******************************************************************/

class Solution {
public:
    void getNext (int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j-1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next,needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j-1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
