class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        // int n = s.size(),j=0,i=0,res = (n+1)*n/2;
        // unordered_map<char,int>freq;
        // while(j<n){
        //     //motu karo
        //     freq[s[j]]++;
        //     while(freq[s[j]]>=k){
        //         freq[s[i]]--;
        //         i++;
        //     }
        //     res-=j-i+1;
        //     j++;        
        // }
        // return res;

        int counter[26]={0},i=0,j=0,count=0,n=s.size();
        while(j<n){
            int c =s[j]-'a';
            counter[c]++;
            while(counter[c]>=k){
                count+=n-j;
                counter[s[i++]-'a']--;
            }
            j++;
        }
    return count;
    }
};