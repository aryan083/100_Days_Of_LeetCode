class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int ans=0;
        int r=0,l=0;
        while(r<s.length()){
            if(m.find(s[r])==m.end()){
                m.insert(s[r]);
                r++;
                ans= max(ans,r-l);
            }else
            {
                m.erase(s[l]);
                l++;

            }
        }
        return ans;
    }
};