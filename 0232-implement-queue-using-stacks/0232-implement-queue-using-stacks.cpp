class MyQueue {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
// Memory Usage: 8.4 MB, less than 5.23% of C++ online submissions for Implement Queue using Stacks.
    
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return !st1.size();
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