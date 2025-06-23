class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i =0; i<=n;i++){
            int temp=i;
            int count=0;
            while( temp >0 ){
                // if(temp & 1)count++;
                // temp=temp>>1;
                temp &=temp-1;
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};