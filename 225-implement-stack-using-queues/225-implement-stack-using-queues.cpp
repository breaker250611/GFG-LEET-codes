class MyStack {
public:
        queue<int>q1;
        queue<int>temp;
    MyStack() {
        
    }
    
    void push(int x) {
        temp.push(x);
        while(!q1.empty()){
            temp.push(q1.front());
            q1.pop();
        }
        q1 = temp;
        queue<int>q2;
        temp = q2;
    }
    
    int pop() {
        int val = top();
        q1.pop();
        return val;
        
    }
    
    int top() {

    return q1.front();
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