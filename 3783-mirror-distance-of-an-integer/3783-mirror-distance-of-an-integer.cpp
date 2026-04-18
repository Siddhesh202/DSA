class Solution {
public:
    int formReverse(int num) {
        int ans = 0;

        while(num > 0) {
            int dig = num % 10;
            num /= 10;
            ans = (ans*10) + dig;
        }

        return ans;
    }

    int mirrorDistance(int n) {
        return abs(n - formReverse(n));
    }
};