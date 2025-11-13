class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()|| t.empty()|| s.size()<t.size()) return "";
        unordered_map<char,int>m;
        for(char c: t){
        m[c]++;
        }
        int count = t.size(),start =0,end=0,minLength = INT_MAX,startIndex=0;
        while(end<s.size()){
            if(m[s[end++]]-- > 0)count--;
            while(count ==0){
                if(end -start<minLength){
                    startIndex=start;
                    minLength=end-start;
                }
                if(m[s[start++]]++==0)count++;
            }
        }
        return minLength ==INT_MAX ? "":s.substr(startIndex,minLength);
    }

};