// using unordered_map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=0;
        while(j<s.size())
        {
            if(mp[s[j]])
            {    
                maxi=max(maxi,j-i);
                mp[s[j]]++;
                while(mp[s[j]]!=1 && j<s.size())
                {
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
            else
            {    
                mp[s[j]]++;
                j++;
                maxi=max(maxi,j-i);
            }
        }
        return maxi;
    }
};


// using unordered_set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int i=0,j=0;
        int maxi=0;
        while(j<s.size())
        {
            if(us.find(s[j])!=us.end())
            {    
                while(us.find(s[j])!=us.end())
                {
                    us.erase(s[i]);
                    i++;
                }
            }
            us.insert(s[j]);
            j++;
            maxi=max(maxi,j-i);
            
        }
        return maxi;
    }
};
