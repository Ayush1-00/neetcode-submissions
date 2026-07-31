class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()||minst.top()>=val)minst.push(val);
    }
    
    void pop() {
        int ele=st.top();
        st.pop();
        if(!minst.empty()&&minst.top()==ele)minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return minst.top(); 
    }
};
