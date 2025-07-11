class Solution {
private:
 public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(),piles.end());
        int high =max,low =1,res=0;
        while( low<=high){
            int mid = low + (high-low)/2;
            unsigned int hours =0;
            for( int k : piles){
                // hours+= (k+mid-1)/mid;
                hours += ceil((double)k / mid);
            }
            if(hours<=h){
                res= mid;
                high = mid-1;
            }else{
                low= mid+1;
            }
        }
        return res;

    }
};