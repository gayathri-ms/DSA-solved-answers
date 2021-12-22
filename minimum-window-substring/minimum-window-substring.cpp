class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++)
        { mp[t[i]]++; }
        int count=mp.size();
        int i=0,j=0;
        int mini=INT_MAX;
        int l=-1,h=-1;
        string ans;
        while(j<s.size() && i<=j)
        {
            if(count>0)
            {
                if(mp[s[j]]>0)
                {
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                    {   
                        count--; 
                        mp[s[j]]=-1;
                    }  
                }
                else if(mp[s[j]]<=-1)
                {
                    mp[s[j]]--;
                }
            }
            if(count == 0)
            {
                if(mini > (j-i+1))
                {
                    mini=j-i+1;
                    l=i;
                    h=j;
                }
                
                while(count==0 && i<s.size())
                {
                    if(mp[s[i]]<0)
                    {
                        if(mp[s[i]]==-1)
                        {
                            mp[s[i]]=1;
                            count++;
                        }
                        else if(mp[s[i]]<-1)
                            mp[s[i]]++;
                    }
                    if(mini > (j-i+1) && i<=j)
                    {
                        mini=j-i+1;
                        l=i;
                        h=j;
                    }
                    i++;
                }
            }
            j++;
        }
        if(l!=-1 && h!=-1)
        {
            ans=s.substr(l,h-l+1);
        }
        return ans;
    }
};