class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> used(26,false);
        for(char c : s)freq[c-'a']++;
        stack<char> ss;
        for(char c: s ){
            freq[c-'a']--;
            if(used[c-'a']) continue;
            while(!ss.empty() && ss.top()>c && freq[ss.top()-'a']>0){
                used[ss.top()-'a']=false;
                ss.pop();
            }
            ss.push(c);
            used[c-'a']=true;
        }
        string ans="";
        while(!ss.empty()){
            ans+=ss.top();
            ss.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};