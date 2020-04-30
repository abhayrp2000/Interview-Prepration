class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1,s2;
    int curr_size;
    MyQueue() {
        curr_size=0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        curr_size++;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            
        }
        
        s1.push(x);
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp=s1.top();
        s1.pop();
        curr_size--;
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return curr_size==0;
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