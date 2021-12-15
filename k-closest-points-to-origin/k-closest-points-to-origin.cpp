typedef pair<int,pair<int,int>> pp;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp> pq;
        
        for(int i=0;i<points.size();i++)
        {
            int val=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({val,{points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size())
        {
            vector<int> v;
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};