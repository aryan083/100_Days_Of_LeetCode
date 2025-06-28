class Solution {
public:
    int countPrimes(int n) {
        int counter=n-2;
        if(n<2) return 0;
        vector<bool> prime( n ,true);
        prime[0]=prime[1]=false;
        for(int p=2;p<=n/p;p++){
            if(prime[p]){
                for( int i=p*p; i<n;i+=p){
                    if(prime[i]){
                        prime[i]=false;
                        counter--;
                    }
                }
            }
        }
        return counter;
    }
};