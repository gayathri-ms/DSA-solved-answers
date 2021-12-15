// bool compare(pair<int,int> a,pair<int,int> b)
// {
//     if (a.second != b.second)
//         return (a.second < b.second);
//     else
//         return (a.first > b.first);
// }
class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        // vector<pair<int,int>> v;
        // for(auto& it : mp)
        // {
        //     v.push_back(make_pair(it.first,it.second));
        // }
        // sort(v.begin(),v.end(),compare);
        // for(int i=0;i<v.size();i++)
        // {
        //     int j=v[i].second;
        //     while(j--)
        //     {
        //         ans.push_back(v[i].first);
        //     }
        // }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto& it:mp)
        {
            pq.push(make_pair(it.second,-1*it.first));
        }
        while(pq.size())
        {
            int j=pq.top().first;
            while(j--)
            { ans.push_back(-1*pq.top().second); }
            pq.pop();
        }
        
        return ans;
    }
};