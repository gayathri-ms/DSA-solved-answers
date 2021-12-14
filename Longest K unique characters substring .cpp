// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int maxi=-1;
        map<int,int> mp;
        int j=0,i=0;
        while(j<s.size())
        {
            mp[s[j]-'a']++;
            if(mp.size()<k)
                j++;
            else if(mp.size()==k)
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(mp.size() > k)
            {
                while(mp.size()>k)
                {
                    mp[s[i]-'a']--;
                    if(mp[s[i]-'a']==0)
                        mp.erase(s[i]-'a');
                    i++;
                }
                j++;
            }
        }
       
        return maxi;
        
    }
};
