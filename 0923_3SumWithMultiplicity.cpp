class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1000000007;
        long count[101] = {0};
        int amt = 0;
        for(int i : arr){
            count[i]++;
            if(count[i] == 1) ++amt;
        }
        
        vector<int> num(amt, 0);
        int j = 0;
        for(int i=0; i<=100; i++){
            if(count[i]) num[j++] = i;
        }
        
        long rt = 0;
        for(int i=0; i<amt; i++){
            int tmp = num[i];
            int tag = target-tmp;
            j = i;
            int k = amt-1;
            while(j <= k){
                int tmp1 = num[j], tmp2 = num[k];
                if(tmp1 + tmp2 < tag) j++;
                else if(tmp1 + tmp2 > tag) k--;
                else{   // ==
                    if(i!=j && j!=k) rt+=count[tmp]*count[tmp1]*count[tmp2];
                    else if(i==j && j!=k) rt+=count[tmp]*(count[tmp]-1)/2*count[tmp2];
                    else if(i!=j && j==k) rt+=count[tmp1]*(count[tmp1]-1)/2*count[tmp];
                    else rt+=count[tmp]*(count[tmp]-1)*(count[tmp]-2)/6;
                    
                    rt %= mod;
                    j++, k--;
                }
            }
        }
        
        return (int)rt;
    }
};
