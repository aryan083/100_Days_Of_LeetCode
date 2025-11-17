class Solution {
public:
    int sol(vector<int>& nums,int left, int right){
        if(left == right)return nums[left];
        int mid = left+(right-left)/2;
        if(nums[mid]<nums[right])return sol(nums,left,mid);
        else return sol(nums,mid+1,right);
    }
    int findMin(vector<int>& nums) {
       return sol(nums,0,nums.size()-1); 
    }
};