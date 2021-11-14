class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> v;
        for(int i=n-1;i>=0;i--)
        {
            while(!v.empty() && temperatures[i]>=temperatures[v.top()])
            {
                v.pop();
            }
            if(!v.empty())
                ans[i]=v.top()-i;
            v.push(i);
        }
        return ans;
    }
};