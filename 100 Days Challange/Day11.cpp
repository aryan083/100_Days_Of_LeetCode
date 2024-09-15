//1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
         // Map to store the first occurrence of each bitmask state
        unordered_map<int, int> mask_index;
        // Initial condition: we have seen the bitmask 0 at index -1
        mask_index[0] = -1;
        
        int mask = 0; // This will track the even/odd status of vowels
        int max_len = 0; // To store the length of the longest valid substring
        
        for (int i = 0; i < s.length(); ++i) {
            // Update the mask based on the current character
            if (s[i] == 'a') {
                mask ^= (1 << 0); // Toggle the 0th bit for 'a'
            } else if (s[i] == 'e') {
                mask ^= (1 << 1); // Toggle the 1st bit for 'e'
            } else if (s[i] == 'i') {
                mask ^= (1 << 2); // Toggle the 2nd bit for 'i'
            } else if (s[i] == 'o') {
                mask ^= (1 << 3); // Toggle the 3rd bit for 'o'
            } else if (s[i] == 'u') {
                mask ^= (1 << 4); // Toggle the 4th bit for 'u'
            }
            
            // Check if we have seen this bitmask before
            if (mask_index.find(mask) != mask_index.end()) {
                // Calculate the length of the substring
                max_len = max(max_len, i - mask_index[mask]);
            } else {
                // If not seen before, store the first occurrence
                mask_index[mask] = i;
            }
        }
        
        return max_len;
    }
};