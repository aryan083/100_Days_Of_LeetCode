class Solution {
public:
int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>entry_count;
        
        int max =0, res=0;
        for( int n : nums){
            // entry_count[n]+=1;
            // if(entry_count[n] > max){
            //     res= n;
            //     max=entry_count[n];
            // }
            if(max==0) res=n;
            // if (n == res)
            //     max += 1;
            // else
            //     max += -1;  // or max -= 1;
            max+=  n==res? 1 :-1;
        }
        return res;
    }
};