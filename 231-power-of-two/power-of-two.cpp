class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;

        for(int i = 0; i < 31; i++) {
            if((1 << i) & n) cnt++;
        }

        // check if 32nd bit is set or not
        if((1 << 31) & n) return false;
        
        return cnt == 1;
    }
};