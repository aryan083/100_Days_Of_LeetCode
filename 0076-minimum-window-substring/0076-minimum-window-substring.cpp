// // class Solution {
// // public:
// //     string minWindow(string s, string t) {
// //         if(s.empty()|| t.empty()|| s.size()<t.size()) return "";
// //         unordered_map<char,int>m;
// //         for(char c: t){
// //         m[c]++;
// //         }
// //         int count = t.size(),start =0,end=0,minLength = INT_MAX,startIndex=0;
// //         while(end<s.size()){
// //             if(m[s[end++]]-- > 0)count--;
// //             while(count ==0){
// //                 if(end -start<minLength){
// //                     startIndex=start;
// //                     minLength=end-start;
// //                 }
// //                 if(m[s[start++]]++==0)count++;
// //             }
// //         }
// //         return minLength ==INT_MAX ? "":s.substr(startIndex,minLength);
// //     }

// // };
// class Solution {
// public:
//     bool isvalid(map<char, int>& ms, map<char, int>& mt) {
//         for (pair<char, int> it : mt) {
//             if ((ms[it.first] < mt[it.first])) {
//                 return false;
//             }
//         }
//         return true;
//     } 
//     void optimizer(int &val,int left,map<char, int>& mt,string &s){
//         while(val<s.size() && mt[s[val]]<1 && val<left-1){
//             val++;
//         }
//     }
//     string minWindow(string s, string t) {
//         map<char, int> mt;
//         map<char, int> ms;
//         for (int i = 0; i < t.length(); i++) {
//             ms[s[i]]++;
//             mt[t[i]]++;
//         }
//         int left = 0;
//         int right = t.length();
//         int min_length = INT_MAX;
        
//         int final_index = 0 , final_length = 0;
//         while (right < s.length() || left < s.length()) {
//             if (isvalid(ms, mt)) {
//                 int len = right - left;
//                 if (len < min_length) {
//                     min_length = len;    
//                     final_index = left;
//                     final_length = len;
//                 }
//                 if (mt[s[left]] != 0) {
//                     ms[s[left]]--;
//                 }
//                     left++;
//                     optimizer(left,INT_MAX,mt,s);
//             } else {
//                 if (right < s.length()) {
//                     if (mt[s[right]] != 0) {
//                         ms[s[right]]++;
//                     }    
//                     right++;
//                     optimizer(right,left,mt,s);
//                 } else if (left < s.length()) {
//                     if (mt[s[left]] != 0) {
//                         ms[s[left]]--;
//                     }
//                     left++;
//                     optimizer(left,INT_MAX,mt,s);
//                 }
//             }
//         }
//         return s.substr(final_index,final_length);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int required = t.size();
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            //bari thai etli moti karo
            if (need[s[r++]] --> 0) { 
                required--;     
            }
            // need[s[r]]--;
            // r++;

            while (required == 0) {

                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                // nanbari nani karo 
                need[s[l]]++;
                if (need[s[l]] > 0) required++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
