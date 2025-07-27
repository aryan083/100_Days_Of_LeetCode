class Solution {
public:
    int helper(vector<int> &v,int n){
        if(v[n]!=-1){return v[n];}
        int temp1 = helper(v , n-1);
        int temp2 = helper(v , n -2) ;
        v[n] = temp1 + temp2 ;
        return v[n] ;


    }
    int climbStairs(int n) {

        if(n <=2) {
            return n ;
        }
        vector<int> v(n+1,-1);
        v[0]=0;v[1]=1;v[2] = 2 ;
        return helper(v,n);

        // if( n==0|| n==1){
        //     return 1;
        // }
        // return climbStairs(n-1)+climbStairs(n-2);
    }
};