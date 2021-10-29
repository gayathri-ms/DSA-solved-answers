class Solution {
public:
    int min(int a , int b){ return ((a<b) ? a : b); }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int t[n+1][amount+1];
        int i=0,j=0;
        
        for(;j<(amount+1);j++)
            if(i==0)
                t[i][j]=INT_MAX-1;
        for(i=1,j=0;i<(n+1);i++)
            if(j==0)
                t[i][j]=0;
        for(i=1,j=0;j<(amount+1);j++)
            if(j%coins[i-1] == 0)
                t[i][j]=j/coins[i-1];
            else
                t[i][j]=INT_MAX-1;
        for(i=2;i<(n+1);i++)
            for(j=1;j<(amount+1);j++)
                if(coins[i-1]<=j)
                    t[i][j]=min(t[i-1][j] , 1+t[i][j-coins[i-1]]);
                else
                    t[i][j]=t[i-1][j];
        
        return ((t[n][amount] == (INT_MAX-1)) ? -1 : t[n][amount]);
    }
};