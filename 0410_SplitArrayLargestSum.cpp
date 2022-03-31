class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // use max sum of subarray to binary search
        int l=0, r=0, mid;
        for(const int i : nums){
            l = max(i, l);
            r += i;
        }
        
        int rt = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(numArr(nums, mid) <= m){
                r = mid-1;
                rt = mid;
            }
            else l = mid+1;
        }
        
        return rt;
    }
    
private:
    int numArr(vector<int>& nums, int n){
        int sum = 0, count = 0;
        for(const int i : nums){
            sum += i;
            if(sum > n){
                count++;
                sum = i;
            }
        }
        return (sum == 0)? count : ++count;
    }
};
