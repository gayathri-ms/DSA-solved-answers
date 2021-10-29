class Solution {
public:
    int max(int a , int b) { return ((a>b) ? a : b);}
    int maxSubArray(vector<int>& nums) {
        
        int maxsum=INT_MIN,sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(sum<=0)
                sum=nums[i];
            else
                sum+=nums[i];
            maxsum=max(maxsum,sum);
        }
        
        return maxsum;
    }
};