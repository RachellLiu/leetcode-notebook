/*************************************************************************************

  232. Implement Queue using Stacks

*************************************************************************************/

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int results = stOut.top();
        stOut.pop();
        return results;
    }
    
    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*************************************************************************************

  225. Implement Stack using Queues

*************************************************************************************/

class MyStack {
public:
    queue<int> myQueue;
    MyStack() {

    }
    
    void push(int x) {
        myQueue.push(x);
    }
    
    int pop() {
        int s = myQueue.size();
        s--;
        while (s--) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
        int result = myQueue.front();
        myQueue.pop();
        return result;
    }
    
    int top() {
        return myQueue.back();
    }
    
    bool empty() {
        return myQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
