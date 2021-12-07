// GFG - https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#

class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans;
        int i=0;
        while(i<n)
        {
            pq.push(arr[i]);
            if(pq.size()>k)
            pq.pop();
            i++;
        }
        while(pq.size())
        {
            ans.insert(ans.begin(),pq.top());
            pq.pop();
        }
        return ans;
    }
};
