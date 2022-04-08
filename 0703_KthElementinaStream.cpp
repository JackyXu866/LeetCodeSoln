class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums){
            pq.push(i);
        }
        int t = nums.size()-k;
        for(; t>0; --t){
            pq.pop();
        }
        _k = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > _k) pq.pop();
        return pq.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int> > pq;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
