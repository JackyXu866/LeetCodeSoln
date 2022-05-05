// if windows64, use long long instead of long

class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        queue<long> *nq = new queue<long>();
        nq->push(x);
        nq->push((long)q);
        q = nq;
    }
    
    int pop() {
        int tmp = q->front();
        
        q->pop();
        queue<long> *tmpq = (queue<long>*)q->front();
        delete q;
        q = tmpq;
        
        return tmp;
    }
    
    int top() {
        return q->front();
    }
    
    bool empty() {
        return !q;
    }
    
private:
    queue<long> *q = nullptr;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
