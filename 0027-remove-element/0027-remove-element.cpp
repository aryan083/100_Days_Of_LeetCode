class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int setter=0;

        for(int i =0;i<nums.size(); i++)
        {
            if(nums[i]!=val){
                nums[setter]=nums[i];
                setter++;

            }
        }
        return setter;

    }
};