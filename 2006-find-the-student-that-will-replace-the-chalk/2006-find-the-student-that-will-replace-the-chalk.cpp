class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size=chalk.size(),total=0;
        
        for( int i =0; i<size;i++ ){
            total+=chalk[i];
            if(total>k) return i;
        }

        k%=total;
        for (int i =0; i < size;i++){
            if(chalk[i] > k){
                return i;
            }
            k-=chalk[i];

        }
        return 0;
    }
};