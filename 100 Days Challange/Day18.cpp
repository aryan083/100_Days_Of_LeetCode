//440. K-th Smallest in Lexicographical Order
class Solution {
public:
    int findKthNumber(int n, int k) {
        int currentPrefix = 1;
        --k;  // Decrement k to handle zero-based indexing
        
        while (k > 0) {
            int count = countNumbersWithPrefix(currentPrefix, n);
            if (k >= count) {
                ++currentPrefix;  // Move to the next prefix
                k -= count;
            } else {
                currentPrefix *= 10;  // Go deeper in the current prefix
                --k;
            }
        }
        
        return currentPrefix;
    }

private:
    int countNumbersWithPrefix(int prefix, int n) {
        long long firstNumber = prefix, nextNumber = prefix + 1;
        int totalCount = 0;

        while (firstNumber <= n) {
            totalCount += static_cast<int>(min(n + 1LL, nextNumber) - firstNumber);
            firstNumber *= 10;
            nextNumber *= 10;
        }

        return totalCount;
    }
};