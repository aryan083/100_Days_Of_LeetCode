class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        vector<int> arr(2,0);
        for( int i=0; i <nums.size();i++){
            for ( int j =i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target) {
                    arr[0]=i;
                    arr[1]=j;
                };
            }
        }
        return arr;
    }

};