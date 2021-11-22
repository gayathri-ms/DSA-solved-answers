class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        bool ans;
        for(int i=0;i<nums.size();i++)
            sum= sum + nums[i];
        
        if(sum%2 != 0)
            return false;
        else if(sum%2 == 0)
        {
            int s=sum/2;
            bool v[n+1][s+1];
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=s;k++)
                {
                    if(k==0 && j==0)
                        v[j][k]=true;
                    else if(j==0)
                        v[j][k]=false;
                    else if(k==0)
                        v[j][k]=true;
                    else if(nums[j-1]<=k)
                    {
                        v[j][k]=(v[j-1][k-nums[j-1]] || v[j-1][k]);
                    }
                    else 
                        v[j][k]=v[j-1][k];
                }
            }
            ans= v[n][s]; 
        }
        return ans;
          
        
    }
    
};