https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

class Solution{
  public:
  long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater <long long>> pq(arr,arr+n) ;
        
        long long sum=0,num1,num2;
        while(pq.size()> 1)
        {
            num1=pq.top();
            pq.pop();
            num2=pq.top();
            pq.pop();
            sum+=(num1+num2);
            pq.push(num1+num2);
        }
        return sum;
    }
};
