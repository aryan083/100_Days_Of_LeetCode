class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int lo = 0;
        int hi = n1 * 2; 
        
        double inf = INT_MAX;
        double neg_inf =INT_MIN;

        while (lo <= hi) {
            int cut1 = (lo + hi) / 2; // The "virtual" cut in nums1
            int cut2 = n1 + n2 - cut1; // The corresponding "virtual" cut in nums2

            // Determine the four boundary elements L1, R1, L2, R2
            // (L1, R1) are from nums1
            // (L2, R2) are from nums2
            
            double L1 = (cut1 == 0) ? neg_inf : nums1[(cut1 - 1) / 2];
            double R1 = (cut1 == n1 * 2) ? inf : nums1[cut1 / 2];
            double L2 = (cut2 == 0) ? neg_inf : nums2[(cut2 - 1) / 2];
            double R2 = (cut2 == n2 * 2) ? inf : nums2[cut2 / 2];

            if (L1 > R2) {
                // L1 is too large, move cut1 to the left
                hi = cut1 - 1;
            } else if (L2 > R1) {
                // L2 is too large, move cut1 to the right
                lo = cut1 + 1;
            } else {
                // Correct partition found (L1 <= R2 && L2 <= R1)
                // The median is (max(L1, L2) + min(R1, R2)) / 2
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
        }
        
        // Should be unreachable if arrays are sorted
        return -1.0; 
    }
};