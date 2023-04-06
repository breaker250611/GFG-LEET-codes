class MyStack {
public:
           queue<int>q1;
        queue<int>q2;
    MyStack() {
 
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(pop());
            // q1.pop();
        }
        swap(q2,q1);
    }
    
    int pop() {
        int value = top();
        q1.pop();
        return value;
    }
    
    int top() {
        int value = q1.front();
        return value;
    }
    
    bool empty() {
        return q1.empty();
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