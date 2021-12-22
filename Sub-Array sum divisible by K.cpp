// https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1#

class Solution{
  public:
    long long subCount(long long arr[], int N, long long K)
    {
        // Your code goes here
        unordered_map<long long,long long> mp;
        mp[0]++;
        long long count=0,sum=0,rem=0;
        for(long long i=0;i<N;i++)
        {
            sum+=arr[i];
            rem=sum%K;
            if(rem<0)
                rem+=K;
            if(mp.find(rem)!=mp.end())
            {
                auto val=mp.find(rem);
                count+=val->second;
            }
            mp[rem]++;

        }
        return count;
    }
};
