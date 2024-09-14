// 2419. Longest Subarray With Maximum Bitwise AND
// 1. If n < max, n & cur_max  <  cur_max
// 2. If n == max, n & cur_max = cur_max
// 3. If n > max, n & cur_max  < cur_max
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx= 0;
        int size=0,res=0;

        
        for (auto n:nums){
            if(n>maxx){maxx=n;size=1;res=0;}
            else if(n==maxx)size+=1;
            else size=0;



        res=max(res,size);

        }
        return res;

    }
};