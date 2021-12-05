class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int ,vector<int>,greater <int>> pq;
        int i=0;
        while(i<nums.size())
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
            i++;
        }
        return pq.top();
    }
};