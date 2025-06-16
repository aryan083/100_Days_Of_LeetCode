typedef vector <int> vi;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return BS(nums,low,high, target);
    }

private: 
    int BS(vi & vec, int low, int high,int target){
        if( high<low) return -1;
        int mid = low + (high-low)/2;
        if ( vec[mid]==target) return mid;
        if( vec[low]<=vec[mid]){
            if(vec[low]<=target && target< vec[mid]) return BS(vec,low,mid-1,target);
            else return BS(vec, mid+1,high,target);
        }else{
            if(vec[mid]<target && target<=vec[high]){
                return BS(vec,mid+1,high,target);
            }else return BS(vec,low,mid-1,target);
        }
    }
};