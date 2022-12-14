/**********************************************************

  344. Reverse String

**********************************************************/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
};

/**********************************************************

  541. Reverse String II
  
  这个可以直接用reverse，内部原理和上题一样

**********************************************************/

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i+=2*k){
            if (i + k <= s.size()) {
                reverse(s.begin()+i,s.begin()+i+k);
                continue;
            }
            reverse(s.begin()+i, s.end());
        }
        return s;
    }
};

/**********************************************************

  剑指 Offer 05. 替换空格 LCOF

**********************************************************/

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        s.resize(oldSize + count * 2);
        int newSize = s.size();
        for (int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            }else{
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};

/**********************************************************

  151. Reverse Words in a String

**********************************************************/

class Solution {
public:
    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j-- ){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces (string &s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i-1);
                start = i + 1;
            }
        }
        return s;
    }
};

/**********************************************************

  剑指 Offer 58 - II. 左旋转字符串 LCOF

**********************************************************/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
