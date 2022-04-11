class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> val;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                val.push_back(grid[i][j]);
        while(k--)
        {
            int temp = val[val.size()-1];
            val.pop_back();
            val.insert(val.begin(),temp);
        }
        int l=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                grid[i][j]=val[l++];
        return grid;
    }
};