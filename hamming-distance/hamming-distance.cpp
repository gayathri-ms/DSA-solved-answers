class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=x^y;
        if(ans)
        {
            int cnt = 0;
            while(ans & (ans-1))
            { 
                cnt++;
                ans=ans&(ans-1);
            }
            cnt++;
            return cnt;
        }
        else 
            return 0;
       
    }
};