class Solution {
public:
    int min (int a , int b) { return (a>b ? b : a); }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days[days.size()-1];
        int dp[n+1];
        dp[0]=0;
        int c1=0 , c7=0 , c30=0;
        int j=0;
        for(int i=1;i<(n+1);i++)
        {
            c1=dp[i-1];
            if(i>=7)
                c7=dp[i-7];
            else
                c7=0;
            if(i>=30)
                c30=dp[i-30];
            else
                c30=0;
            if(days[j]==i)
            {
                dp[i]=min(min(c1+costs[0] , c7+costs[1]) , c30+costs[2]);
                j++;
            }    
            else
                dp[i]=dp[i-1];
                
        }
        
        return dp[n];
    }
};