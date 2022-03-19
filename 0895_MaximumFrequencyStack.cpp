class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int tmp = ++freq[val];
        maxFreq = max(tmp, maxFreq);
        vals[tmp].push(val);
    }
    
    int pop() {
        int rt = vals[maxFreq].top();
        vals[maxFreq].pop();
        --freq[rt];
        if(vals[maxFreq].empty()) --maxFreq;
        return rt;
    }
    
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> vals; // key = freq; value = elements
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
