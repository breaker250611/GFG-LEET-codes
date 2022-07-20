class MinStack {
public:
    stack<int>st;
    vector<int>min;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.size()==0){
            min.push_back(val);
        }
        else{
            if(min.back()>=val) min.push_back(val);
        }
    }
    
    void pop() {
        int x = top();
        int y = getMin();
        if(x==y){
            min.pop_back();
        }
        st.pop();
        // return x;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */