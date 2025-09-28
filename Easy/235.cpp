class MyQueue {
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int n = s.size();
        vector<int> v;

        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        s.push(x);

        for (int i = v.size() - 1; i >= 0; i--) {
            s.push(v[i]);
        }

    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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
