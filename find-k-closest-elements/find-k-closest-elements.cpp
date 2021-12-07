class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<arr.size();i++)
        {
            int diff=abs(arr[i]-x);
            pq.push(make_pair(diff,arr[i]));
            if(pq.size()>k)
                pq.pop();
        }
        priority_queue<int,vector<int>,greater<int>> ans;
        vector<int> a;
        while(pq.size())
        {
            ans.push(pq.top().second);
            pq.pop();
        }
        while(ans.size())
        {
            a.push_back(ans.top());
            ans.pop();
        }
        return a;
    }
};