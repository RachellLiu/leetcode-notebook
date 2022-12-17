/**************************************************************

  20. Valid Parentheses
  
  3种情况：1左括号多了 2右括号多了 3左右不匹配

**************************************************************/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else if (st.empty() || s[i] != st.top()) return false;
            else st.pop();
        }
        return st.empty();
    }
};

/**************************************************************

  1047. Remove All Adjacent Duplicates In String
  
  先用stack写的，然后发现用string更简单

**************************************************************/

class Solution {
public:
    string removeDuplicates(string s) {
        string results;
        for (char a: s) {
            if (results.empty() || a != results.back()) results.push_back(a);
            else results.pop_back();
        }
        return results;
    }
};

/**************************************************************

  150. Evaluate Reverse Polish Notation

**************************************************************/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long t2 = st.top();
                st.pop();
                long t1 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(t1+t2);
                if (tokens[i] == "-") st.push(t1-t2);
                if (tokens[i] == "*") st.push(t1*t2);
                if (tokens[i] == "/") st.push(t1/t2);
            }else{
                st.push(stol(tokens[i]));  // Convert string to long int: s to l
            }
        }
        return st.top();
    }
};
