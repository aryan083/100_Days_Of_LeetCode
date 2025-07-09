class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total_total=0;
        for( int i =0 ; i<nums.size();i++){
            total_total+=nums[i];
        }
        int currTotal =0;
        for ( int i =0;i<nums.size();i++){
            if(total_total-currTotal-nums[i]==currTotal) return i;
            currTotal+=nums[i];

        }
        return -1;
            }
};