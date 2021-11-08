class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> m;
        int i=0,j=0;
        int n=p.size();
        int count=0;
        for(int k=0;k<p.size();k++)
        {
            if(m.find(p[k]-'a')==m.end())
                count++;
            m[p[k]-'a']++;
        }
        while(j<s.size())
        {
            if(j-i+1 < n)
            {
                if(m.find(s[j]-'a')!= m.end())
                {
                    m[s[j]-'a']--;
                    if(m[s[j]-'a'] == 0)
                        count--;
                }
                j++;
            }
            if( j-i+1 == n)
            {
                if(m.find(s[j]-'a')!= m.end())
                {
                    m[s[j]-'a']--;
                    if(m[s[j]-'a'] == 0)
                        count--;
                }
                if(count==0)
                    ans.push_back(i);
                if(m.find(s[i]-'a')!= m.end())
                {
                    m[s[i]-'a']++;
                    if(m[s[i]-'a'] == 1)
                        count++;
                }
                    
                
                j++,i++;
            }
        }
        return ans;
        
    }
};