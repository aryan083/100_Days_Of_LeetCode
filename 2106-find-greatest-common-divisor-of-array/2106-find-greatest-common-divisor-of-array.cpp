class Solution {
public:
    int findHCF(int n, int m){
        // if(m>n)swap(m,n);
        if(m==0){return n;}
        return findHCF(m,n%m);    
    }

    int findGCD(vector<int>& nums) {
        int max1=*max_element(nums.begin(),nums.end());
        int min1=*min_element(nums.begin(),nums.end());
        int ans= gcd(min1,max1);

        return ans;
    }
};