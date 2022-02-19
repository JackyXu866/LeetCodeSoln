class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum;
        int rt = 0;
        for(const int a : nums1){
            for(const int b : nums2){
                sum[a+b]++;
            }
        }
        
        for(const int c : nums3){
            for(const int d : nums4){
                rt += sum[-c-d];
            }
        }
        
        return rt;
    }
};
