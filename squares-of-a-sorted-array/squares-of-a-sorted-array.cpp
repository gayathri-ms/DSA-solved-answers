class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
                v1.push_back(nums[i]*nums[i]);
            else 
                v2.insert(v2.begin(),nums[i]*nums[i]);
        }
        vector<int> ans;
        int j=0,k=0,i=0;
        while(j<v1.size() && k<v2.size() && i<nums.size())
        {
            if(v1[j]>v2[k])
                ans.push_back(v2[k++]);
            else
                ans.push_back(v1[j++]);
        }
        if(j<v1.size())
            while(j<v1.size())
                ans.push_back(v1[j++]);
        if(k<v2.size())
            while(k<v2.size())
                ans.push_back(v2[k++]);
        
        return ans;
    }
};