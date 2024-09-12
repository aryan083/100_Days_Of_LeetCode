// 1684. Count the Number of Consistent Strings
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedMask = 0;
    for (char ch : allowed) {
        allowedMask |= (1 << (ch - 'a'));
    }

    int consistentCount = 0;

    // Iterate through each word
    for (string word : words) {
        int wordMask = 0;
        // Create a bitmask for the word
        for (char ch : word) {
            wordMask |= (1 << (ch - 'a'));
        }

        // Check if the word's mask is a subset of allowedMask
        if ((wordMask & allowedMask) == wordMask) {
            consistentCount++;
        }
    }

    return consistentCount;
    }
};