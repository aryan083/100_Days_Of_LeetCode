// // Source - https://stackoverflow.com/q/22615838
// // Posted by Sahil Sareen, modified by community. See post 'Timeline' for change history
// // Retrieved 2025-11-07, License - CC BY-SA 3.0

// void computeLPSArray(char *pat, int M, int *lps)
// {
//     int len = 0;  // length of the previous longest prefix suffix
//     int i;

//     lps[0] = 0; // lps[0] is always 0
//     i = 1;

//     // the loop calculates lps[i] for i = 1 to M-1
//     while(i < M)
//     {
//        if(pat[i] == pat[len])
//        {
//          len++;
//          lps[i] = len;
//          i++;
//        }
//        else // (pat[i] != pat[len])
//        {
//          if( len != 0 )
//          {
//            // This is tricky. Consider the example AAACAAAA and i = 7.
//            len = lps[len-1]; //*****************

//            // Also, note that we do not increment i here
//          }
//          else // if (len == 0)
//          {
//            lps[i] = 0;
//            i++;
//          }
//        }
//     }
// }


class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        lps[0]=0;
        for(int i =1 ,len =0;i<s.size();i++){
            while(len>0 && s[i]!=s[len]){
                len=lps[len-1];
            }
            if(s[i]==s[len])
                len++;
            lps[i] = len;
        }
        return s.substr(0,lps[s.length()-1]);
    }
    // string longestPrefix(string s) {
    //     int n = s.size(), len = 0;
    //     vector<int> lps(n);
    //     for(int i = 1; i < n; i++){
    //         while(len > 0 && s[i] != s[len])
    //             len = lps[len-1];
    //         if(s[i] == s[len])
    //             len++;
    //         lps[i] = len;
    //     }
    //     return s.substr(0, lps[n-1]);
    // }
};





// aaaaaa