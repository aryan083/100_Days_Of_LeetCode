class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int counter =1,maxSize=1;
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)counter++;
            else if(nums[i]!= nums[i-1])counter =1;
            maxSize= max(maxSize,counter);
        }
        return maxSize;
    }
};