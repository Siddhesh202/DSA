class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false, canBeOdd = true, canBeEven = true;

        // Find smallest odd
        for (int num : nums1) {
            if (num % 2 != 0) {
                hasOdd = true;
                minOdd = min(minOdd, num);
            }
        }

        // If no odd → already uniform (all even)
        if (!hasOdd) return true;

        // 1. Try creating odd parity
        for(int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];

            // check if there is an odd elem smaller than this
            if(num % 2 == 0 && minOdd > num) {
                canBeOdd = false;
                break;
            }

        }


        return canBeOdd;
    }
};

// 1. odd - odd = even
// 2. even - even = even
// 3. even - odd = odd

// If I need to make an odd arr 2 conditions
// 1. num should be odd itself
// 2. if num is even, there should be an odd elem smaller than this elem

// If I need to make an even arr
// 1. num should be even itself
// 2. if num is odd, there should be an odd elem smaller than this elem