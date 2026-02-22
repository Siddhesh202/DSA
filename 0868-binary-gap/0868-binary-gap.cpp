class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, prev = -1;

        for(int i = 0; i < 32; i++) {
            bool isBitSet = n & (1 << i);

            if(isBitSet) {
                if(prev != -1) {
                    ans = max(ans, i - prev);
                }
                prev = i;
            } 
        }

        return ans;
    }
};